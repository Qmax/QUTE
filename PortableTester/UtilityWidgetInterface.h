#ifndef UtilityINTERFACE_H
#define UtilityINTERFACE_H
#include <QObject>
#include <QWidget>
class UtilityInterface
{
public:
	virtual QWidget* getUtility()=0;
};

Q_DECLARE_INTERFACE(UtilityInterface,"pt.UtilityInterface/1.0.0.1");
#endif // UtilityINTERFACE_H
