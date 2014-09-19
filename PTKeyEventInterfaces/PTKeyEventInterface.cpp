#include <PtKeyEventInterface.h>
#if 1
#define qLog(x) qDebug()
#else
#define qLog(x) while (0) qDebug()
#endif

#define DEV_NAME  "pt_kpp"


void  PTKeyEventInterface::InvokeGPIOEvent(QWidget *parent,QString driver, QString device,int *pKeyCode)
{
    //qDebug()<<"GPIO event invoked";
    g_objKeyevent = new PTKeyEvent(parent,pKeyCode);
    g_objKeyevent->create(driver,device);

}

void PTKeyEventInterface::closefd()
{
        g_objKeyevent->callclosefd();
}
bool PTKeyEventInterface::BlockSig(bool get)
{
//        qDebug()<<"inside Blocksig";
        if(get==true){
            g_objKeyevent->blockSignals(true);
           // qDebug()<<"Signal Blocked";
        }
        else if(get==false){
       g_objKeyevent->blockSignals(false);
      // qDebug()<<"Signal UnBlocked";
        }
        return true;
}

Q_EXPORT_PLUGIN2(PTKeyEventInterface, PTKeyEventInterface)

PTKeyEvent::PTKeyEvent(QWidget *parent,int *pKeyCode):QWidget(parent)
{
    //qDebug()<<"----------------------------GPIO LIBRARY KEY EVENT STARTS----------------------------";

        m_TW = parent;
        m_nKey = pKeyCode;
}

PTKeyEvent::~PTKeyEvent(){
}

void PTKeyEvent::create(QString driver, QString pDevice)
{
    char name[50] = "Unknown";
    char *device = new char[50];
    int l_nDeviceIndex=0;
    // Initial Routine for closing the Input Devices
    /*for(l_nDeviceIndex=0;l_nDeviceIndex < 32; l_nDeviceIndex++) {
           strcpy(device,"/dev/input/event");
           char str[2];
           sprintf(str,"%d", l_nDeviceIndex);
           strcat(device,str);
           if((kbdFD = ::open(device,O_RDONLY)) == -1){
               ::close(kbdFD);
           }
           ::close(kbdFD);
       }*/
     for(l_nDeviceIndex=0;l_nDeviceIndex < 32; l_nDeviceIndex++){
        strcpy(device,"/dev/input/event");
        char str[2];
        sprintf(str,"%d", l_nDeviceIndex);
        strcat(device,str);
//        printf("Inside PTKeyboardDevice %s\n",device);
        if((kbdFD = ::open(device,O_RDONLY)) == -1){
             printf ("%s is not a vaild device.\n", device);
        }
        // Get Device Name
        ioctl (kbdFD, EVIOCGNAME (sizeof (name)), name);
        if(strcmp(name,DEV_NAME) == 0)
        {
            ::close(kbdFD);
            break;
        }
    }
    if(l_nDeviceIndex ==31 )
        return;
    QString m_strDeviceName;
    QFile *m_nDevice;
    m_strDeviceName=device;
//    printf("%s\n",name);
    m_nDevice = new QFile(m_strDeviceName);
    //qDebug() << m_strDeviceName;
    kbdFD = ::open(device,O_RDONLY);
    if(kbdFD >=0){
    m_notify = new QSocketNotifier(kbdFD, QSocketNotifier::Read,this);
    connect(m_notify, SIGNAL(activated(int)), this, SLOT(readKbdData()));
    //qDebug()<<"PTKeyPad Handler created!";
    }
    else    {
        qDebug()<<"PTKeyPad Handler Problem!";
    }

        /*
    QMessageBox msgbox;
    //msgbox.setText("Inside Create");
    //msgbox.exec();
    qLog(Input) << "Loaded GPIOEvent plugin!";
    qLog(Input) << driver;
    qLog(Input) << device;
    char name[50] = "Unknown";
    setObjectName( "GPIOEVENT Handler" );
    kbdFD = ::open(driver.toLocal8Bit().constData(), O_RDONLY);
    if (kbdFD >= 0) {
        qLog(Input) << "Opened" << device << "as GPIO input";
        m_notify = new QSocketNotifier( kbdFD, QSocketNotifier::Read, this );

        ioctl (kbdFD, EVIOCGNAME (sizeof (name)), name);
        if(strcmp(name,DEV_NAME) == 0)
                connect( m_notify, SIGNAL(activated(int)), this, SLOT(readKbdData()));
    } else {
        qWarning("Cannot open '%s' for keypad (%s)",device.toLocal8Bit().constData(), strerror(errno));
        return;
    }
    shift = false;
*/
}
int PTKeyEvent::callclosefd()
{
        int cl;
        cl=::close(kbdFD);
        return cl;
}
TranslatedKeyEvent::TranslatedKeyEvent(input_event const &event):
                unicode_(0),keyCode_(0),isPress_(event.value == 1),autoRepeat_(event.value == 2){
    unicode_ = 0xffff;
    switch(event.code)    {
     case 0x1FF7: keyCode_ = PT_MENU; break;
     case 0x1FFB: keyCode_ = PT_ESC; break;
     case 0x1FFD: keyCode_ = PT_NULL; break;
     case 0x1FFE: keyCode_ = PT_RARROW; break;

     case 0x2FF7: keyCode_ = PT_F1; break;
     case 0x2FFB: keyCode_ = PT_SETUP; break;
     case 0x2FFD: keyCode_ = PT_NULL; break;
     case 0x2FFE: keyCode_ = PT_ENTER; break;

     case 0x37F7: keyCode_ = PT_F2; break;
     case 0x37FB: keyCode_ = PT_DEFAULT; break;
     case 0x37FD: keyCode_ = PT_NULL; break;
     case 0x37FE: keyCode_ = PT_SCALE; break;

     case 0x3BF7: keyCode_ = PT_F3; break;
     case 0x3BFB: keyCode_ = PT_TOUCH; break;
     case 0x3BFD: keyCode_ = PT_UARROW; break;
     case 0x3BFE: keyCode_ = PT_NULL; break;

     case 0x3DF7: keyCode_ = PT_F4; break;
     case 0x3DFB: keyCode_ = PT_FILE; break;
     case 0x3DFD: keyCode_ = PT_DARROW; break;
     case 0x3DFE: keyCode_ = PT_NULL; break;

     case 0x3EF7: keyCode_ = PT_F5; break;
     case 0x3EFB: keyCode_ = PT_RUNORSTOP; break;
     case 0x3EFD: keyCode_ = PT_LARROW; break;
     case 0x3EFE: keyCode_ = PT_NULL; break;
     default:   break;
    }
}
void PTKeyEvent::readKbdData()
{
    struct input_event event;
    const int eventSize(sizeof(struct input_event));
    int n= read(kbdFD,&event,sizeof(struct input_event));
        if(event.type != EV_PT_KEY)        {
                //qDebug()<<" if loop"<<event.type;
            // We should handle only key events
            return;
        }
        //qDebug()<<"PTKeyEventInterface : event code :"<<event.code;
        TranslatedKeyEvent translatedEvent(event);
        *m_nKey = translatedEvent.keyCode_;
        //emit pressed(translatedEvent.keyCode_);
        QApplication::postEvent(m_TW,new QEvent(PTKeyEventCode));

}

