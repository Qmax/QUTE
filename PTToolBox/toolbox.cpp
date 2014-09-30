#include "toolbox.h"
#include "ui_toolbox.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBox)
{
    ui->setupUi(this);
      setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
      this->setGeometry( QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));

//    setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint & ~Qt::WindowMinimizeButtonHint);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setStartValue(QRect(250, 100, 350, 0));
    animation->setEndValue(QRect(250, 100, 350, 300));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->setDuration(300);
    animation->start();

    QPluginLoader testjig("libPortableTesterTestJig2.so", this);
    testJig = qobject_cast<IPTTestjigInterface*> (testjig.instance());

    loginDialog = new LoginDialog( this );
	connect(loginDialog,SIGNAL(acceptLogin(QString&,QString&,int&)),this,SLOT(slotAcceptUserLogin(QString&,QString&)));

	//~~~~~~~~~~~~~Reading cursor state~~~~~~~~~~~~~~~~~~~~~~
		QStringList stringList;		QFile textFile;		QString m_strState;
		textFile.setFileName("cursorState.txt");
		if (textFile.open(QIODevice::ReadOnly)) {
			QTextStream textStream(&textFile);
			while (!textStream.atEnd()) {
				stringList.append(textStream.readLine());
			}
			m_strState= stringList.value(0);
		}
		if(m_strState=="true"){
			m_bCursor=true;
			ui->pb_curEnDis->setIcon(QIcon(":/res/Very-Basic-Cursor-icon.png"));
		}
		else{
			m_bCursor=false;
		    ui->pb_curEnDis->setIcon(QIcon(":/res/Very-Basic-Hand-Cursor-icon.png"));
		}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}

ToolBox::~ToolBox()
{
    delete ui;
}

void ToolBox::changeEvent(QEvent *e)
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

void ToolBox::on_pb_testjig_clicked()
{
	int retryloop=0;
           do{
	               loginDialog->exec();
	               retryloop++;
	               if(retryloop==3){
	                   break;
	               }
	           }while(!m_nPassword);
           if(m_nPassword==true/* && retryloop!=3*/){
        	    QWidget *newWidget = testJig->getPTTestjig();
        	    newWidget->show();
           }
}

void ToolBox::on_pb_selftest_clicked()
{

}
void ToolBox::on_pb_touchcalib_clicked()
{
//    QProcess compile;
//    compile.setWorkingDirectory("/home");
//    compile.setReadChannel(QProcess::StandardOutput);
//    compile.setProcessChannelMode(QProcess::MergedChannels);
//    QTextStream out(stdout);
//
//    compile.start("source",QStringList() << "calibrtae.sh");
//    compile.waitForFinished(-1);
//
//    QByteArray msg = compile.readAllStandardOutput();
//    if(msg.isEmpty())
//    {
//        qDebug() << "Successful";
//    }
//    else qDebug() << msg;

//__________________________________________________________________________________________________________
	QFile outFile;
	outFile.setFileName("calibrate.sh");
	outFile.open(QIODevice::WriteOnly);
	QTextStream ts(&outFile);
	ts << "/usr/bin/qt-embedded/ts_calibrate";

    QMessageBox msgbox;
    msgbox.setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    msgbox.setFont(QFont("DejaVu Sans", 15, 50, false));
    msgbox.setIcon(QMessageBox::Information);
	 msgbox.setText("Touch Screen Calibration Enabled.\nRestart the System to Calibrate.");
	 msgbox.setStandardButtons(QMessageBox::Ok);
	 msgbox.exec();
	 //__________________________________________________________________________________________________________
}

void ToolBox::on_pb_datetime_clicked()
{
    DateTime *dt=new DateTime();
    dt->show();
}
void ToolBox::slotAcceptUserLogin(QString& name,QString& password){
        if(name=="root" && password=="root"){
                m_nPassword=true;
        }else{
                QMessageBox msg;
                msg.setText("Login Error");
                msg.setInformativeText("Invalid Username/Password");
                msg.exec();
                m_nPassword=false;
                //        this->close();
        }

}

void ToolBox::on_pb_exit_clicked()
{
    this->close();
}

void ToolBox::on_pb_curEnDis_clicked()
{
	QProcess process;
    if(m_bCursor==true){
    	process.startDetached("/bin/sh", QStringList()<< "touch.sh");
      QWSServer::setCursorVisible( false );
      ui->pb_curEnDis->setIcon(QIcon(":/res/Very-Basic-Hand-Cursor-icon.png"));
      m_bCursor=false;
    }else{
    	process.startDetached("/bin/sh", QStringList()<< "mouse.sh");
      ui->pb_curEnDis->setIcon(QIcon(":/res/Very-Basic-Cursor-icon.png"));
      QWSServer::setCursorVisible( true );
      m_bCursor=true;
    }

	//~~~~~~~~~~~~~Writing cursor state~~~~~~~~~~~~~~~~~~~~~~
	QFile outFile;
	outFile.setFileName("cursorState.txt");
	outFile.open(QIODevice::WriteOnly);
	QTextStream ts(&outFile);
	if(m_bCursor==true)		ts << "true";
	else					ts << "false";
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~~~~~~~~~~~Writing profile file ~~~~~~~~~~~~~~~~~~~~~~
	QFile outFile2;
	QString envMouse = "source /etc/functions.sh\nexport $(grep '^DEL_PLATFORM' /etc/version)\nexport TSLIB_TSDEVICE=\"/dev/event0\"\nexport QWS_MOUSE_PROTO=\"tslib:/dev/event0 Auto\"\nexport TSLIB_TSDEVICE=\"/dev/input/ts0\"\nexport QWS_MOUSE_PROTO=\"tslib:/dev/input/ts0 Auto\"\n_touch_select=\"$(imx51_touch_selection)\"\n[ \"${_touch_select}\" = \"0\" ] && export TSLIB_CONFFILE=\"/etc/ts.conf.ads\"\n[ \"${_touch_select}\" = \"1\" ] && export TSLIB_CONFFILE=\"/etc/ts.conf.mxc\"";
	QString envTouch = "source /etc/functions.sh\nexport $(grep '^DEL_PLATFORM' /etc/version)\nexport TSLIB_TSDEVICE=\"/dev/event0\"\nexport QWS_MOUSE_PROTO=\"tslib:/dev/event0 \"\nexport TSLIB_TSDEVICE=\"/dev/input/ts0\"\nexport QWS_MOUSE_PROTO=\"tslib:/dev/input/ts0 \"\n_touch_select=\"$(imx51_touch_selection)\"\n[ \"${_touch_select}\" = \"0\" ] && export TSLIB_CONFFILE=\"/etc/ts.conf.ads\"\n[ \"${_touch_select}\" = \"1\" ] && export TSLIB_CONFFILE=\"/etc/ts.conf.mxc\"";
	outFile2.setFileName("/etc/profile");
	outFile2.open(QIODevice::WriteOnly);
	QTextStream ts2(&outFile2);
	if(m_bCursor==true)	ts2<<envMouse;
	else				ts2<<envTouch;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    QMessageBox msgbox;
    msgbox.setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    msgbox.setFont(QFont("DejaVu Sans", 15, 50, false));
    msgbox.setIcon(QMessageBox::Information);
    if(m_bCursor==true)
	 msgbox.setText("Mouse Enabled.\nRestart the System.");
    else
     msgbox.setText("Touch Enabled.\nRestart the System.");
	 msgbox.setStandardButtons(QMessageBox::Ok);
	 msgbox.exec();

}
