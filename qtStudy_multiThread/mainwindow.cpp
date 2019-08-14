#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThread>
#include <QDebug>

typedef uint32_t __u32;
typedef int32_t __s32;
typedef uint64_t __u64;

/* useful defines */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define do_div(a,b) a = (a) / (b)

#define abs(x) ({               \
    long __x = (x);             \
    (__x < 0) ? -__x : __x;     \
  })

struct can_bittiming
{
  __u32 bitrate; /* Bit-rate in bits/second */
  __u32 sample_point; /* Sample point in one-tenth of a percent */
  __u32 tq; /* Time quanta (TQ) in nanoseconds */
  __u32 prop_seg; /* Propagation segment in TQs */
  __u32 phase_seg1; /* Phase buffer segment 1 in TQs */
  __u32 phase_seg2; /* Phase buffer segment 2 in TQs */
  __u32 sjw; /* Synchronisation jump width in TQs */
  __u32 brp; /* Bit-rate prescaler */
};

typedef struct flexcan_bittiming
{
    struct can_bittiming cbt;
    __u32 prop_seg;
    __u32 phase_seg1;
    __u32 phase_seg2;
    __u32 rjw; // resync jump width
    __u32 pdf; // prescaler devision factor
} flexcan_bittiming_t;

/*
 * CAN harware-dependent bit-timing constant
 *
 * Used for calculating and checking bit-timing parameters
 */
struct can_bittiming_const
{
  char name[ 16 ]; /* Name of the CAN controller hardware */
  __u32 tseg1_min; /* Time segement 1 = prop_seg + phase_seg1 */
  __u32 tseg1_max;
  __u32 tseg2_min; /* Time segement 2 = phase_seg2 */
  __u32 tseg2_max;
  __u32 sjw_max; /* Synchronisation jump width */
  __u32 brp_min; /* Bit-rate prescaler */
  __u32 brp_max;
  __u32 brp_inc;
  __u32 ipt;

  /* added for can-calc-bit-timing utility */
  __u32 ref_clk; /* CAN system clock frequency in Hz */
  void (*printf_btr)( struct can_bittiming *bt, int hdr );
  void (*fn_transbit_str)(struct can_bittiming *cbt, struct flexcan_bittiming *fbt);
};

/*
 * CAN clock parameters
 */
struct can_clock
{
  __u32 freq; /* CAN system clock frequency in Hz */
};

/*
 * minimal structs, just enough to be source level compatible
 */
struct can_priv
{
  const struct can_bittiming_const *bittiming_const;
  struct can_clock clock;
};

struct net_device
{
  struct can_priv priv;
};

QVector<flexcan_bittiming_t> g_matchedCBTs;

static inline void *netdev_priv( const struct net_device *dev )
{
  return (void *) &dev->priv;
}

static void printf_btr_flexcan( struct can_bittiming *bt, int hdr )
{
    return;
}

static void std_transbit_str(struct can_bittiming *cbt, struct flexcan_bittiming *fbt)
{
    memcpy(&fbt->cbt, cbt, sizeof(*cbt));
    fbt->prop_seg = cbt->prop_seg;
    fbt->phase_seg1 = cbt->phase_seg1 - 2;
    fbt->phase_seg2 = cbt->phase_seg2 - 1;
    fbt->rjw = cbt->sjw;
    fbt->pdf = cbt->brp - 1;

    return;
}

static void fd_data_transbit_str(struct can_bittiming *cbt, struct flexcan_bittiming *fbt)
{
    memcpy(&fbt->cbt, cbt, sizeof(*cbt));
    fbt->prop_seg = cbt->prop_seg;
    fbt->phase_seg1 = cbt->phase_seg1 - 1;
    fbt->phase_seg2 = cbt->phase_seg2 - 1;
    fbt->rjw = cbt->sjw;
    fbt->pdf = cbt->brp - 1;

    return;
}

static struct can_bittiming_const can_calc_consts[ ] = {
{
    .name = {'f', 'l', 'e', 'x', 'c', 'a', 'n', '_', 's', 't', 'd', '\0'},
    .tseg1_min = 2, .tseg1_max = 16, .tseg2_min = 2,
    .tseg2_max = 8, .sjw_max = 4, .brp_min = 1, .brp_max = 256, .brp_inc = 1, .ipt = 2,
    .ref_clk = 40000000,
    .printf_btr = printf_btr_flexcan,
    .fn_transbit_str = std_transbit_str,
},
{
    .name = {'f', 'l', 'e', 'x', 'c', 'a', 'n', '_', 'f', 'd', 'a', '\0'},
    .tseg1_min = 2, .tseg1_max = 96, .tseg2_min = 2,
    .tseg2_max = 32, .sjw_max = 4, .brp_min = 1, .brp_max = 256, .brp_inc = 1, .ipt = 2,
    .ref_clk = 40000000,
    .printf_btr = printf_btr_flexcan,
    .fn_transbit_str = std_transbit_str,
},
{
    .name = {'f', 'l', 'e', 'x', 'c', 'a', 'n', '_', 'f', 'd', 'd', '\0'},
    .tseg1_min = 2, .tseg1_max = 39, .tseg2_min = 2,
    .tseg2_max = 8, .sjw_max = 4, .brp_min = 1, .brp_max = 256, .brp_inc = 1, .ipt = 2,
    .ref_clk = 40000000,
    .printf_btr = printf_btr_flexcan,
    .fn_transbit_str = fd_data_transbit_str,
}

};

/*!
 * \brief can_update_spt
 * \param btc
 * \param sampl_pt
 * \param tseg
 * \param tseg1
 * \param tseg2
 * \return simple point(%) * 1000
 */
static int can_update_spt( const struct can_bittiming_const *btc, int sampl_pt,
  int tseg, int *tseg1, int *tseg2 )
{
    *tseg2 = tseg + 1 - ( sampl_pt * ( tseg + 1 ) ) / 1000;
    if ( *tseg2 < btc->tseg2_min )
        *tseg2 = btc->tseg2_min;
    if ( *tseg2 > btc->tseg2_max )
        *tseg2 = btc->tseg2_max;
    *tseg1 = tseg - *tseg2;
    if ( *tseg1 > btc->tseg1_max )
    {
        *tseg1 = btc->tseg1_max;
        *tseg2 = tseg - *tseg1;
    }
    return 1000 * ( tseg + 1 - *tseg2 ) / ( tseg + 1 );
}

static int can_calc_bittiming( struct net_device *dev, struct can_bittiming *bt )
{
    struct can_priv *priv = (can_priv *)netdev_priv( dev );
    const struct can_bittiming_const *btc = priv->bittiming_const;
    long rate = 0;
    long best_error = 1000000000, error = 0;
    int best_tseg = 0, best_brp = 0, brp = 0;
    int tsegall, tseg = 0, tseg1 = 0, tseg2 = 0;
    int spt_error = 1000, spt = 0, sampl_pt;
    __u64 v64;

    if ( !priv->bittiming_const )
        return -1;

    g_matchedCBTs.clear();

    /* Use CIA recommended sample points */
    if ( bt->sample_point ) {
        sampl_pt = bt->sample_point;
    } else {
        if ( bt->bitrate > 800000 )
            sampl_pt = 750;
        else if ( bt->bitrate > 500000 )
            sampl_pt = 800;
        else
            sampl_pt = 875;
    }

    /* tseg even = round down, odd = round up */
    for ( tseg = ( btc->tseg1_max + btc->tseg2_max ) * 2 + 1;
          tseg >= ( btc->tseg1_min + btc->tseg2_min ) * 2; tseg-- )
    {
        tsegall = 1 + tseg / 2;
        /* Compute all possible tseg choices (tseg = tseg1+tseg2) */
        brp = priv->clock.freq / ( tsegall * bt->bitrate ) + tseg % 2;
        /* chose brp step which is possible in system */
        brp = ( brp / btc->brp_inc ) * btc->brp_inc;
        if ( ( brp < btc->brp_min ) || ( brp > btc->brp_max ) )
            continue;

        rate = priv->clock.freq / ( brp * tsegall );
        error = bt->bitrate - rate;
        /* record the one best match the disired bitrate */
        if ( error < 0 )
            error = -error;
        if ( error > best_error )
            continue;
        best_error = error;

        /* bitrate is exactly match, update simple point and do match checking */
        if ( error == 0 ) {
            spt = can_update_spt( btc, sampl_pt, tseg / 2, &tseg1, &tseg2 );
            error = sampl_pt - spt;
            if ( error < 0 )
                error = -error;
            if ( error > spt_error )
                continue;
            spt_error = error;
        }
        best_tseg = tseg / 2;
        best_brp = brp;

        /* simple point match too, let's record the right parameters */
        if ( error == 0 ) {
            /* real sample point */
            bt->sample_point = spt;
            v64 = (__u64) best_brp * 1000000000UL;
            do_div( v64, priv->clock.freq );
            bt->tq = (__u32) v64;
            bt->prop_seg = (tseg1/2);
            __u32 left = tsegall - 1 - bt->prop_seg;
            if (left%2) {
                bt->prop_seg++;
            }
            bt->phase_seg1 = tseg1 - bt->prop_seg;
            bt->phase_seg2 = tseg2;
            bt->sjw = 1;
            bt->brp = best_brp;
            bt->bitrate = priv->clock.freq / ( bt->brp * ( tseg1 + tseg2 + 1 ) );

            flexcan_bittiming_t fbt;
            btc->fn_transbit_str(bt, &fbt);
            g_matchedCBTs.append(fbt);
        }
    }

    for (const flexcan_bittiming_t &fbt : g_matchedCBTs) {
        qDebug() << QObject::tr("TQ(%1) PROG_SEG(%2) PHASE_SEG1(%3) PHASE_SEG2(%4) BRP(%5) RJW(%6)").\
                    arg(fbt.cbt.tq).\
                    arg(fbt.prop_seg).\
                    arg(fbt.phase_seg1).\
                    arg(fbt.phase_seg2).\
                    arg(fbt.pdf).\
                    arg(fbt.rjw);
    }

    return g_matchedCBTs.isEmpty()?-1:0;
}

static void print_bit_timing( const struct can_bittiming_const *btc,
  __u32 bitrate, __u32 sample_point, __u32 ref_clk)
{
    struct net_device dev;
    struct can_bittiming bt;
    long rate_error, spt_error;

    dev.priv.bittiming_const = btc;
    dev.priv.clock.freq = ref_clk;
    bt.bitrate = bitrate;
    bt.sample_point = sample_point;

    if ( can_calc_bittiming( &dev, &bt ) )
    {
        printf( "%7d ***bitrate not possible***\n", bitrate );
        return;
    }
}

static int flexcan_bitiming_print()
{
    char name[16] = "flexcan_fda";
    __u32 bitrate = 500000;
    __u32 ref_clk = 40000000;
    int sampl_pt = 800;
    const struct can_bittiming_const *btc = NULL;

    for ( int i = 0; i < ARRAY_SIZE( can_calc_consts ); i++ )
    {
        if ( name && strcmp( can_calc_consts[ i ].name, name ) )
            continue;

        btc = &can_calc_consts[ i ];
        print_bit_timing(btc, bitrate, sampl_pt, ref_clk);
    }

    return 0;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flexcan_bitiming_print();
    //startWorker();
}

MainWindow::~MainWindow()
{
    stopWorker();
    delete ui;
}

void MainWindow::startWorker()
{
    m_workThread = new QThread();
    m_worker = new Worker();
    m_worker->moveToThread(m_workThread);
    QObject::connect(m_workThread, &QThread::started, m_worker, &Worker::run);
    QObject::connect(m_workThread, &QThread::finished, m_worker, &Worker::deleteLater);
    QObject::connect(m_workThread, &QThread::finished, m_workThread, &QThread::deleteLater);
    //QObject::connect(this, &MainWindow::workStop, m_worker, &Worker::onWorkStop);

    m_workThread->start(QThread::HighPriority);
    qDebug() << "Worker thread started.";
}

void MainWindow::stopWorker()
{
    //emit workStop();

    if(m_workThread && (!m_workThread->isFinished())) {
        m_workThread->quit();
        if(!m_workThread->wait()) {
            qDebug() << "can't stop thread";
        }
        qDebug() << "Worker thread finished.";
    }
}
