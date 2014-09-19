/**
 * (C) 2010 Wolfgang Plaschg <wolfgang.plaschg@gmail.com>
 * Licensed under MIT-LICENSE 
 */
#include <QPen>
#include "EffectLabel.h"

EffectLabel::EffectLabel(QWidget* parent) :
	QLabel(parent),
	effect_(Plain)
{ }

void EffectLabel::drawTextEffect(QPainter *painter, 
                                 QPoint offset)
{
	Q_ASSERT(painter != 0); 
	
	// Draw shadow.
	painter->setPen(QPen(Qt::black));
	painter->drawText(rect().translated(offset),
	                  alignment(), text());
	// Draw text.
	painter->setPen(QPen(Qt::gray));
	painter->drawText(rect(), alignment(), text());
}

void EffectLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
	QPainter painter(this);
	painter.setFont(font());
	if (effect_ == Plain)
        painter.drawText(rect(), alignment(), text());
	else if (effect_ == Sunken) 
	    // Shadow above the text.
	    drawTextEffect(&painter, QPoint(0, -1));
	else if (effect_ == Raised) 
	    // Shadow below the text.
	    drawTextEffect(&painter, QPoint(0, 1));
}
