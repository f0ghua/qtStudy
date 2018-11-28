#ifndef ICSVFILE_H
#define ICSVFILE_H

#include "idevctrl_global.h"
#include <QObject>

#define CSV_MAX_FILESIZE        (64*1024*1024)
#define CSV_BACKUP_COUNT        32

class ICsvFilePrivate;

/*!
 * \brief The ICsvFile class
 *
 * The class implement base functions for products from
 * JuYing(http://www.juyingele.com.cn/)
 *
 */
class IDEVCTRLIBSHARED_EXPORT ICsvFile : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ICsvFile)
public:
    enum QuoteOption {
        NoQuotes = 0,
        SingleQuote = 1,
        DoubleQuote = 2,
        BothQuotes = 3,
        NoEscape = 0,
        TwoQuoteEscape = 4,
        BackslashEscape = 8,
        AlwaysQuoteOutput = 16,
        DefaultQuoteMode = BothQuotes | BackslashEscape | AlwaysQuoteOutput
    };
    Q_DECLARE_FLAGS(QuoteMode, QuoteOption)

    ICsvFile(QObject *parent = NULL, qint64 size = CSV_MAX_FILESIZE, int count = CSV_BACKUP_COUNT);
    explicit ICsvFile(const QString& filePath, QObject *parent = Q_NULLPTR, qint64 size = CSV_MAX_FILESIZE, int count = CSV_BACKUP_COUNT);
    ~ICsvFile();

    void setHeader(QList<QStringList> &headerList);
    void setPath(const QString &filePath);
    void writeHeaders();
    int write(const QStringList &rowCells);
    QuoteMode quoteMode() const;
    void setQuoteMode(QuoteMode mode);
    void close();

protected:
    ICsvFile(ICsvFilePrivate &dd, QObject *parent = Q_NULLPTR);

private:
    ICsvFilePrivate * const d_ptr;
    Q_DISABLE_COPY(ICsvFile)
};

Q_DECLARE_OPERATORS_FOR_FLAGS(ICsvFile::QuoteMode)

#endif // ICSVFILE_H
