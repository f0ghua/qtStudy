#include "icsvfile.h"

#define ROTATION_SUPPORT

#ifdef ROTATION_SUPPORT
#include "QsLogDestFile.h"
using namespace QsLogging;
#endif

#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(APP_CSV, "app.csv")
Q_LOGGING_CATEGORY(APP_CSV_LOW, "app.csv.lowlevel")

#define CSV_SEPARATOR   ','

class ICsvFilePrivate : public QObject
{
    Q_DECLARE_PUBLIC(ICsvFile)
public:
    ICsvFilePrivate(qint64 size, int count, ICsvFile *parent);
    ICsvFilePrivate(const QString& filePath, qint64 size, int count, ICsvFile *parent);
    virtual ~ICsvFilePrivate();

    void createRotationStrategy(qint64 size, int count);
    void setPath(const QString &filePath);
    void writeHeaders();
    int write(const QStringList &rowCells);
    void close();

    ICsvFile * const q_ptr;
    QString m_filePath;
    QFile m_file;
    QTextStream m_outputStream;
    ICsvFile::QuoteMode m_quoteMode = ICsvFile::DefaultQuoteMode;
    QList<QStringList> m_headers;
#ifdef ROTATION_SUPPORT
    RotationStrategy *m_rotationStrategy = NULL;
#endif
};

void ICsvFilePrivate::createRotationStrategy(qint64 size, int count)
{
    Q_Q(ICsvFile);
#ifdef ROTATION_SUPPORT
    SizeRotationStrategy *rotationStrategy = new SizeRotationStrategy();
    rotationStrategy->setMaximumSizeInBytes(size);
    rotationStrategy->setBackupCount(count);
    m_rotationStrategy = rotationStrategy;
#endif
}

ICsvFilePrivate::ICsvFilePrivate(qint64 size, int count, ICsvFile *parent)
    : q_ptr(parent)
{
    createRotationStrategy(size, count);
}

ICsvFilePrivate::ICsvFilePrivate(const QString& filePath, qint64 size, int count, ICsvFile *parent)
    : q_ptr(parent)
    , m_filePath(filePath)
{
    Q_Q(ICsvFile);

    createRotationStrategy(size, count);

    m_file.setFileName(filePath);
    if (!m_file.open(QFile::WriteOnly | QFile::Text)) {
        qCWarning(APP_CSV) << "QsLog: could not open csv file " << qPrintable(filePath);
        return;
    }
    m_outputStream.setDevice(&m_file);
    m_outputStream.setCodec(QTextCodec::codecForName("UTF-8"));
}

ICsvFilePrivate::~ICsvFilePrivate()
{
    close();
}

void ICsvFilePrivate::close()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}

void ICsvFilePrivate::setPath(const QString &filePath)
{
    Q_Q(ICsvFile);

    m_filePath = filePath;

    if (m_file.isOpen()) {
        m_file.close();
    }

    m_file.setFileName(filePath);
    if (!m_file.open(QFile::WriteOnly | QFile::Text)) {
        qCWarning(APP_CSV) << "could not open csv file " << qPrintable(filePath);
        return;
    }
    m_outputStream.setDevice(&m_file);
    m_outputStream.setCodec(QTextCodec::codecForName("UTF-8"));
}

static QString addCsvQuotes(ICsvFile::QuoteMode mode, QString field)
{
    bool addDoubleQuotes = ((mode & ICsvFile::DoubleQuote) && field.contains('"'));
    bool addSingleQuotes = ((mode & ICsvFile::SingleQuote) && field.contains('\''));
    bool quoteField = (mode & ICsvFile::AlwaysQuoteOutput) || addDoubleQuotes || addSingleQuotes;
    if(quoteField && !addDoubleQuotes && !addSingleQuotes) {
        if(mode & ICsvFile::DoubleQuote)
            addDoubleQuotes = true;
        else if(mode & ICsvFile::SingleQuote)
            addSingleQuotes = true;
    }
    if(mode & ICsvFile::BackslashEscape) {
        if(addDoubleQuotes)
            return '"' + field.replace("\\", "\\\\").replace("\"", "\\\"") + '"';
        if(addSingleQuotes)
            return '\'' + field.replace("\\", "\\\\").replace("'", "\\'") + '\'';
    } else {
        if(addDoubleQuotes)
            return '"' + field.replace("\"", "\"\"") + '"';
        if(addSingleQuotes)
            return '\'' + field.replace("'", "''") + '\'';
    }
    return field;
}

void ICsvFilePrivate::writeHeaders()
{
    if (!m_file.isOpen())
        return;

    // append the header
    foreach (QStringList header, m_headers) {
        QString headerStr = header.join(CSV_SEPARATOR);
#ifdef ROTATION_SUPPORT
        m_rotationStrategy->includeMessageInCalculation(headerStr);
#endif
        m_outputStream << headerStr << endl;
        m_outputStream.flush();
    }
}

int ICsvFilePrivate::write(const QStringList &rowCells)
{
    if (!m_file.isOpen())
        return -1;

    QString data;
    for(int col = 0; col < rowCells.length(); ++col) {
        if(col > 0) data += CSV_SEPARATOR;
        data += addCsvQuotes(m_quoteMode, rowCells.at(col));
    }

#ifdef ROTATION_SUPPORT
    m_rotationStrategy->includeMessageInCalculation(data);
    if (m_rotationStrategy->shouldRotate()) {
        m_outputStream.setDevice(nullptr);
        m_file.close();
        m_file.flush();
        m_rotationStrategy->rotate();
        if (!m_file.open(QFile::WriteOnly | QFile::Text |
                         m_rotationStrategy->recommendedOpenModeFlag())) {
            qCWarning(APP_CSV) << "ICsvFile: could not reopen csv file " << qPrintable(m_file.fileName());
        }
        m_rotationStrategy->setInitialInfo(m_file);
        m_outputStream.setDevice(&m_file);
        m_outputStream.setCodec(QTextCodec::codecForName("UTF-8"));

        writeHeaders();
    }
#endif

    m_outputStream << data << endl;
    m_outputStream.flush();
    return 0;
}

ICsvFile::ICsvFile(QObject *parent, qint64 size, int count)
    : QObject(parent)
    , d_ptr(new ICsvFilePrivate(size, count, this))
{
    Q_D(ICsvFile);
}

ICsvFile::ICsvFile(const QString& filePath, QObject *parent, qint64 size, int count)
    : QObject(parent)
    , d_ptr(new ICsvFilePrivate(filePath, size, count, this))
{
    Q_D(ICsvFile);
}

void ICsvFile::setPath(const QString &filePath)
{
    Q_D(ICsvFile);
    d->setPath(filePath);
}

void ICsvFile::writeHeaders()
{
    Q_D(ICsvFile);
    d->writeHeaders();
}

ICsvFile::~ICsvFile()
{
    delete d_ptr;
}

ICsvFile::ICsvFile(ICsvFilePrivate &dd, QObject *parent)
    : d_ptr(&dd)
{

}

void ICsvFile::setHeader(QList<QStringList> &headerList)
{
    Q_D(ICsvFile);

    d->m_headers = headerList;
}

int ICsvFile::write(const QStringList &rowCells)
{
    Q_D(ICsvFile);

    return d->write(rowCells);
}

ICsvFile::QuoteMode ICsvFile::quoteMode() const
{
    Q_D(const ICsvFile);
    return d->m_quoteMode;
}

void ICsvFile::setQuoteMode(QuoteMode mode)
{
    Q_D(ICsvFile);
    d->m_quoteMode = mode;
}

void ICsvFile::close()
{
    Q_D(ICsvFile);
    d->close();
}
