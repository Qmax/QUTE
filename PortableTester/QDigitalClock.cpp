

#include "QDigitalClock.h"

QDigitalClock::QDigitalClock(QWidget* parent) : QWidget(parent)
{
    // Create and connect the timer
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(update()));
    m_pTimer->start(DIGITAL_CLOCK_DEFAULT_INTERVAL);

    // Set defaults
    m_TextColor = DIGITAL_CLOCK_DEFAULT_TEXT_COLOR;
    m_Format    = DIGITAL_CLOCK_DEAULT_FORMAT;
    m_Interval  = DIGITAL_CLOCK_DEFAULT_INTERVAL;
    m_Alignment = DIGITAL_CLOCK_DEAULT_ALIGNMNET;

    // Paint initial
    update();
}

QDigitalClock::~QDigitalClock() 
{   
    m_pTimer->stop();
    delete m_pTimer;
}

// Paint the clock
void QDigitalClock::paintEvent(QPaintEvent*)
{
    QDateTime DateTime = QDateTime::currentDateTime();

    // No need to set the font, default font property is used (QWidget)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect PainterRect = painter.window();

    // Paint
    painter.setPen(QPen(m_TextColor));
    painter.drawText(PainterRect, m_Alignment, DateTime.toString(m_Format));
}

// Property "textColor"
QColor QDigitalClock::textColor() const
{
    return m_TextColor;
}

void QDigitalClock::SetTextColor(QColor TextColor)
{
    m_TextColor = TextColor;
    update();
}

void QDigitalClock::ResetTextColor()
{
    m_TextColor = DIGITAL_CLOCK_DEFAULT_TEXT_COLOR;
    update();
}

// Property "format"
QString QDigitalClock::format() const
{
    return m_Format;
}

void QDigitalClock::SetFormat(QString Format)
{
    m_Format = Format;
    update();
}

void QDigitalClock::ResetFormat()
{
    m_Format = DIGITAL_CLOCK_DEAULT_FORMAT;
    update();
}

// Property "interval"
int QDigitalClock::interval() const
{
    return m_Interval;
}

void QDigitalClock::SetInterval(int Interval)
{
    m_Interval = Interval;
    if(m_Interval < DIGITAL_CLOCK_INTERVAL_MIN)
    {
        m_Interval = DIGITAL_CLOCK_INTERVAL_MIN;
    }
    if(m_Interval > DIGITAL_CLOCK_INTERVAL_MAX)
    {
        m_Interval = DIGITAL_CLOCK_INTERVAL_MAX;
    }

    m_pTimer->setInterval(m_Interval);
    update();
}

void QDigitalClock::ResetInterval()
{
    m_Interval = DIGITAL_CLOCK_DEFAULT_INTERVAL;
    m_pTimer->setInterval(m_Interval);
    update();
}

// Property "alignment"
Qt::Alignment QDigitalClock::alignment() const
{
    return m_Alignment;
}

void QDigitalClock::SetAlignment(Qt::Alignment Alignment)
{
    m_Alignment = Alignment;
    update();
}

void QDigitalClock::ResetAlignment()
{
    m_Alignment = DIGITAL_CLOCK_DEAULT_ALIGNMNET;
    update();
}

// Property "minimumSizeHint" overwritten
QSize QDigitalClock::minimumSizeHint() const
{
    return QSize(DIGITAL_CLOCK_WIDTH_MINIMUM, DIGITAL_CLOCK_HEIGHT_MINIMUM);
}

// Property "sizeHint" overwritten
QSize QDigitalClock::sizeHint() const
{
    return QSize(DIGITAL_CLOCK_WIDTH_DEFAULT, DIGITAL_CLOCK_HEIGHT_DEFAULT);
}
