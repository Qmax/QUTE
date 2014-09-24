#include "datetime.h"
#include "ui_datetime.h"

DateTime::DateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTime)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    this->setGeometry( QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setStartValue(QRect(200, 100, 0, 350));
    animation->setEndValue(QRect(200, 100, 400, 350));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(300);
    animation->start();

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->dateTimeEdit,SIGNAL(dateChanged(QDate)),ui->calendarWidget,SLOT(setSelectedDate(QDate)));
}

DateTime::~DateTime()
{
    delete ui;
}

void DateTime::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DateTime::on_pb_exit_clicked()
{
    this->close();
}

void DateTime::executeSystemCommand(QString Command,QString args){
    QProcess::execute(Command+" "+args);
    QProcess::execute("hwclock --systohc");
}

void DateTime::on_dateTimeEdit_dateTimeChanged(QDateTime date2)
{
    qDebug()<<"~~~~~~~~~~~~~"<<date2;
    QString l_strDate=date2.toString();
    QStringList l_arryDate=l_strDate.split(" ");
    QStringList l_arryTime=l_arryDate.at(3).split(":");
    QString date,month,hour,minute,year;

    if(l_arryDate.at(1)=="Jan")month="01";    if(l_arryDate.at(1)=="Feb")month="02";    if(l_arryDate.at(1)=="Mar")month="03";
    if(l_arryDate.at(1)=="Apr")month="04";    if(l_arryDate.at(1)=="May")month="05";    if(l_arryDate.at(1)=="Jun")month="06";
    if(l_arryDate.at(1)=="Jul")month="07";    if(l_arryDate.at(1)=="Aug")month="08";    if(l_arryDate.at(1)=="Sep")month="09";
    if(l_arryDate.at(1)=="Oct")month="10";    if(l_arryDate.at(1)=="Nov")month="11";    if(l_arryDate.at(1)=="Dec")month="12";

    date=l_arryDate.at(2);
    hour=l_arryTime.at(0);
    minute=l_arryTime.at(1);
    year=l_arryDate.at(4);
    if(l_arryDate.at(2)=="1")date="01"; if(l_arryDate.at(2)=="2")date="02";if(l_arryDate.at(2)=="3")date="03";
    if(l_arryDate.at(2)=="4")date="04"; if(l_arryDate.at(2)=="5")date="05";if(l_arryDate.at(2)=="6")date="06";
    if(l_arryDate.at(2)=="7")date="07"; if(l_arryDate.at(2)=="8")date="08";if(l_arryDate.at(2)=="9")date="09";

    if(l_arryTime.at(0)=="1")hour="01"; if(l_arryTime.at(0)=="2")hour="02";if(l_arryTime.at(0)=="3")hour="03";
    if(l_arryTime.at(0)=="4")hour="04"; if(l_arryTime.at(0)=="5")hour="05";if(l_arryTime.at(0)=="6")hour="06";
    if(l_arryTime.at(0)=="7")hour="07"; if(l_arryTime.at(0)=="8")hour="08";if(l_arryTime.at(0)=="9")hour="09";

    if(l_arryTime.at(1)=="1")minute="01"; if(l_arryTime.at(1)=="2")minute="02";if(l_arryTime.at(1)=="3")minute="03";
    if(l_arryTime.at(1)=="4")minute="04"; if(l_arryTime.at(1)=="5")minute="05";if(l_arryTime.at(1)=="6")minute="06";
    if(l_arryTime.at(1)=="7")minute="07"; if(l_arryTime.at(1)=="8")minute="08";if(l_arryTime.at(1)=="9")minute="09";

    if(l_arryDate.at(4)=="1")year="01"; if(l_arryDate.at(4)=="2")year="02";if(l_arryDate.at(4)=="3")year="03";
    if(l_arryDate.at(4)=="4")year="04"; if(l_arryDate.at(4)=="5")year="05";if(l_arryDate.at(4)=="6")year="06";
    if(l_arryDate.at(4)=="7")year="07"; if(l_arryDate.at(4)=="8")year="08";if(l_arryDate.at(4)=="9")year="09";

    cmd=month+date+hour+minute+year;

}

void DateTime::on_pb_Apply_clicked()
{

    executeSystemCommand("date",cmd);
}
