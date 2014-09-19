

#ifndef QDIGITALCLOCK_H
#define QDIGITALCLOCK_H

#include <QtGui>
#include <QtDesigner/QDesignerExportWidget>


// Height
const int DIGITAL_CLOCK_HEIGHT_MINIMUM      = 10;
const int DIGITAL_CLOCK_HEIGHT_DEFAULT      = 20;

// Width
const int DIGITAL_CLOCK_WIDTH_MINIMUM       = 20;
const int DIGITAL_CLOCK_WIDTH_DEFAULT       = 120;

// Interval
const int DIGITAL_CLOCK_DEFAULT_INTERVAL    = 1000;  // msec delay

const int DIGITAL_CLOCK_INTERVAL_MIN        = 10;
const int DIGITAL_CLOCK_INTERVAL_MAX        = 1000000;

// Default color
const QColor DIGITAL_CLOCK_DEFAULT_TEXT_COLOR   = Qt::black;

// Default format
const char DIGITAL_CLOCK_DEAULT_FORMAT[]        = "dd.MM.yyyy HH:mm:ss";

// Default alignment
const Qt::Alignment DIGITAL_CLOCK_DEAULT_ALIGNMNET  = Qt::AlignLeft | Qt::AlignVCenter;


/*
    Class that defines a digital clock widget. 
    The clock's look is customizable with different properties.

    Format expressions:
    d       the day as number without a leading zero (1 to 31)
    dd      the day as number with a leading zero (01 to 31)
    ddd     the abbreviated localized day name (e.g. 'Mon' to 'Sun'). Uses QDate::shortDayName().
    dddd    the long localized day name (e.g. 'Qt::Monday' to 'Qt::Sunday'). Uses QDate::longDayName().
    M       the month as number without a leading zero (1-12)
    MM      the month as number with a leading zero (01-12)
    MMM     the abbreviated localized month name (e.g. 'Jan' to 'Dec'). Uses QDate::shortMonthName().
    MMMM    the long localized month name (e.g. 'January' to 'December'). Uses QDate::longMonthName().
    yy      the year as two digit number (00-99)
    yyyy    the year as four digit number

    h       the hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)
    hh      the hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)
    H       the hour without a leading zero (0 to 23, even with AM/PM display)
    HH      the hour with a leading zero (00 to 23, even with AM/PM display)
    m       the minute without a leading zero (0 to 59)
    mm      the minute with a leading zero (00 to 59)
    s       the second without a leading zero (0 to 59)
    ss      the second with a leading zero (00 to 59)
    z       the milliseconds without leading zeroes (0 to 999)
    zzz     the milliseconds with leading zeroes (000 to 999)
    AP or A interpret as an AM/PM time. AP must be either "AM" or "PM".
    ap or a Interpret as an AM/PM time. ap must be either "am" or "pm".
*/
class QDigitalClock : public QWidget
{
    Q_OBJECT

public:

    QDigitalClock(QWidget* parent = 0);
     ~QDigitalClock();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

     // Property getter
    QColor textColor() const;
    QString format() const;
    int interval() const;
    Qt::Alignment alignment() const;

public slots:

    // Property setter
    void SetTextColor(QColor);
    void SetFormat(QString);
    void SetInterval(int);
    void SetAlignment(Qt::Alignment);

    // Property resetter
    void ResetTextColor();
    void ResetFormat();
    void ResetInterval();
    void ResetAlignment();

protected:

    // Paint the clock
    void paintEvent(QPaintEvent *event);

public:

    // Timer
    QTimer* m_pTimer;

    // Property member
    QColor m_TextColor;
    QString m_Format;
    int m_Interval;
    Qt::Alignment m_Alignment;
};

#endif // QDIGITALCLOCK_H
