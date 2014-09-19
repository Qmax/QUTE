//#ifndef QMAXPTLIBRARY_H
//#define QMAXPTLIBRARY_H
//
//#include <QMap>
//#include <QList>
//#include <QtGui>
//#include <QVariant>
//#include <qmaxbutton.h>
//#include <InterfacePTLibrary.h>
//
//
//    class QmaxPTLibrary:public QObject {
//        Q_OBJECT
//        //Q_INTERFACES(PTInterfaceObject)
//    public:
//        QmaxPTLibrary(QObject *p=0)
//        {
//            Q_UNUSED(p);
////            static ObjectFactoryTemplate<QmaxPTLibrary> objPTLibrary;
////            ObjectFactory objExterFactory;
////            static ObjectFactoryRegister objReg("QmaxPTLibrary",&objPTLibrary,&objExterFactory);
////            qDebug()<<"Qmax PT Library";
//        }
//        void InitPTLibrary(QString pStrFileName,QString pStrWindowName);
//        unsigned int m_nNumber;
//    protected:
//        QList<PT_MENU*> ReadPanel(QString);
//        QMap<QString, QList<PT_MENU*> > *m_mapMainWindowMenus;
//        QString m_strWindowName,m_strFileName;
//    };
//
//
//#endif // QMAXPTLIBRARY_H
