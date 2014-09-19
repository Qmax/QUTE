#include "KeyObject.h"

KeyObject::KeyObject()
{

}
bool KeyObject::eventFilter(QObject *obj, QEvent *event)
{
        printf("Event Type1:%d\n",event->type());
        if(event->type() == ((QEvent::Type)1234))
        {
                printf("PTKeyboardEventconfigured\n");
        }
        return QObject::eventFilter(obj, event);
}

void KeyObject::receiveData(int pData)
{
        printf("Received Key Data %d\n",pData);
}


