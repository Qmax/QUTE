#ifndef PTLMH6518INTERFACE_H
#define PTLMH6518INTERFACE_H
#include <QObject>
#include <QtCore>
#include <QWidget>
class IPTLMH6518Interface
{
public:
	virtual QWidget* getPTLMH6518()=0;
};

Q_DECLARE_INTERFACE(IPTLMH6518Interface,"pt.PTLMH6518Interface/1.0.0.1");
#endif
