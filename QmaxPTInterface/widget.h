#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qmaxbutton.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);
    QString validateKey(QString pKey);
    void changeKeyPad();
    QmaxButton *m_objVKeyButtons[60];
    QString m_strText;
    bool m_ShiftKey;
    bool m_altKey;
    bool m_ctrlKey;
    bool m_capsKey;
    int m_nPosistion;
private:
    Ui::Widget *ui;
    void constructVirtualKeyboard();
    void InitialisePTVkeyMap();
    QMap<int,QString> m_mapPTVKeys;
public slots:
    void buttonPressed(int);
};

#endif // WIDGET_H
