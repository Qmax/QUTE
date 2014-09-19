/*
*
 * (C) 2010 Wolfgang Plaschg <wolfgang.plaschg@gmail.com>
 * Licensed under MIT-LICENSE 
 */
#ifndef EFFECTLABEL_H
#define EFFECTLABEL_H

#ifdef _DESIGNER_EXPORT
#include <QDesignerExportWidget>
#else
#define QDESIGNER_WIDGET_EXPORT
#endif

#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>

class QDESIGNER_WIDGET_EXPORT EffectLabel : public QLabel
{
	Q_OBJECT

public:

    /* These properties are accessible by Qt Designer*/
    Q_PROPERTY(Effect effect READ effect WRITE setEffect)

    /* Tell Designer about the Enum */
    Q_ENUMS(Effect);

	enum Effect {
	    Plain = 0,
		Sunken,
		Raised
	};

	EffectLabel(QWidget* parent = 0);

	void paintEvent(QPaintEvent *event);

	Effect effect() const
	{ return effect_; }

	void setEffect(Effect effect)
	{ effect_ = effect; repaint(); }

private:
   void drawTextEffect(QPainter* painter, QPoint offset);

	Effect effect_;

};

#endif
