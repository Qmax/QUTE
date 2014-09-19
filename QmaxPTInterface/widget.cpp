#include "widget.h"
#include "ui_widget.h"
#include <QTextCursor>


Widget::Widget(QWidget *parent) :
        QWidget(parent,Qt::Window),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->textEdit->moveCursor(QTextCursor::Right,QTextCursor::MoveAnchor);
    //ui->textEdit->textCursor().setPosition(0,QTextCursor::MoveAnchor);
    m_strText ="";
    InitialisePTVkeyMap();
    ui->lineEdit->setCursorPosition(0);
    constructVirtualKeyboard();
}

void Widget::InitialisePTVkeyMap()
    {
        // 1st Row
        m_mapPTVKeys.insert(0,"~ `");
        m_mapPTVKeys.insert(1,"! 1");
        m_mapPTVKeys.insert(2,"@ 2");
        m_mapPTVKeys.insert(3,"# 3");
        m_mapPTVKeys.insert(4,"$ 4");
        m_mapPTVKeys.insert(5,"% 5");
        m_mapPTVKeys.insert(6,"^ 6");
        m_mapPTVKeys.insert(7,"& 7");
        m_mapPTVKeys.insert(8,"* 8");
        m_mapPTVKeys.insert(9,"( 9");
        m_mapPTVKeys.insert(10,") 0");
        m_mapPTVKeys.insert(11,"_ -");
        m_mapPTVKeys.insert(12,"+ =");
        m_mapPTVKeys.insert(13,"<-BKsp");

        //2nd Row
        m_mapPTVKeys.insert(14,"Tab->");
        m_mapPTVKeys.insert(15,"q");
        m_mapPTVKeys.insert(16,"w");
        m_mapPTVKeys.insert(17,"e");
        m_mapPTVKeys.insert(18,"r");
        m_mapPTVKeys.insert(19,"t");
        m_mapPTVKeys.insert(20,"y");
        m_mapPTVKeys.insert(21,"u");
        m_mapPTVKeys.insert(22,"i");
        m_mapPTVKeys.insert(23,"o");
        m_mapPTVKeys.insert(24,"p");
        m_mapPTVKeys.insert(25,"{ [");
        m_mapPTVKeys.insert(26,"} ]");
        m_mapPTVKeys.insert(27,"| \\");

        // 3rd Row
        m_mapPTVKeys.insert(28,"Caps Lock");
        m_mapPTVKeys.insert(29,"a");
        m_mapPTVKeys.insert(30,"s");
        m_mapPTVKeys.insert(31,"d");
        m_mapPTVKeys.insert(32,"f");
        m_mapPTVKeys.insert(33,"g");
        m_mapPTVKeys.insert(34,"h");
        m_mapPTVKeys.insert(35,"j");
        m_mapPTVKeys.insert(36,"k");
        m_mapPTVKeys.insert(37,"l");
        m_mapPTVKeys.insert(38,": ;");
        m_mapPTVKeys.insert(39,"\" \'");
        m_mapPTVKeys.insert(40,"Enter");

        //4th Row
        m_mapPTVKeys.insert(41,"Shift");
        m_mapPTVKeys.insert(42,"z");
        m_mapPTVKeys.insert(43,"x");
        m_mapPTVKeys.insert(44,"c");
        m_mapPTVKeys.insert(45,"v");
        m_mapPTVKeys.insert(46,"b");
        m_mapPTVKeys.insert(47,"n");
        m_mapPTVKeys.insert(48,"m");
        m_mapPTVKeys.insert(49,"< ,");
        m_mapPTVKeys.insert(50,"> .");
        m_mapPTVKeys.insert(51,"? /");
        m_mapPTVKeys.insert(52,"UP");
        m_mapPTVKeys.insert(53,"DEL");

        // 5th Row
        m_mapPTVKeys.insert(54,"Ctrl");
        m_mapPTVKeys.insert(55,"Alt");
        m_mapPTVKeys.insert(56," ");
        m_mapPTVKeys.insert(57,"LEFT");
        m_mapPTVKeys.insert(58,"DOWN");
        m_mapPTVKeys.insert(59,"RIGHT");


    }



void Widget::buttonPressed(int pKeyCode)
{

    m_strText+=validateKey(m_mapPTVKeys.value(pKeyCode));
    m_strText.simplified();
    int posValue = ui->lineEdit->cursorPosition();
    m_nPosistion = posValue;
    ui->lineEdit->setText(m_strText);
    if(m_mapPTVKeys.value(pKeyCode).contains("Caps Lock"))
    {
        if(m_objVKeyButtons[pKeyCode]->readStatus() == false)
            m_objVKeyButtons[pKeyCode]->changeStatus(1);
        else
            m_objVKeyButtons[pKeyCode]->changeStatus(0);
        m_objVKeyButtons[pKeyCode]->refresh();
    }
    if(m_mapPTVKeys.value(pKeyCode).contains("Shift"))
    {
        if(m_objVKeyButtons[pKeyCode]->readStatus() == false)
            m_objVKeyButtons[pKeyCode]->changeStatus(1);
        else
            m_objVKeyButtons[pKeyCode]->changeStatus(0);
        m_objVKeyButtons[pKeyCode]->refresh();
    }
    if(m_mapPTVKeys.value(pKeyCode).contains("DEL"))
    {
        ui->lineEdit->setCursorPosition(posValue);
    }
    if(m_mapPTVKeys.value(pKeyCode).contains("<-BKsp"))
        ui->lineEdit->setCursorPosition(posValue-1);
    else if(!m_mapPTVKeys.value(pKeyCode).contains("DEL"))
        ui->lineEdit->setCursorPosition(posValue+1);
}

void Widget::changeKeyPad()
{
    for(int l_nButtonIndex=15;l_nButtonIndex<25;l_nButtonIndex++)
    {
        if(m_objVKeyButtons[28]->readStatus() == false){
            m_objVKeyButtons[l_nButtonIndex]->setText(m_mapPTVKeys.value(l_nButtonIndex).toUpper());
            m_mapPTVKeys[l_nButtonIndex] = m_mapPTVKeys.value(l_nButtonIndex).toUpper();
            }
        else{
            m_objVKeyButtons[l_nButtonIndex]->setText(m_mapPTVKeys.value(l_nButtonIndex).toLower());
            m_mapPTVKeys[l_nButtonIndex] = m_mapPTVKeys.value(l_nButtonIndex).toLower();
            }

    }
    for(int l_nButtonIndex=29;l_nButtonIndex<=37;l_nButtonIndex++)
    {
        if(m_objVKeyButtons[28]->readStatus() == false){
            m_objVKeyButtons[l_nButtonIndex]->setText(m_mapPTVKeys.value(l_nButtonIndex).toUpper());
            m_mapPTVKeys[l_nButtonIndex] = m_mapPTVKeys.value(l_nButtonIndex).toUpper();
            }
        else{
            m_objVKeyButtons[l_nButtonIndex]->setText(m_mapPTVKeys.value(l_nButtonIndex).toLower());
            m_mapPTVKeys[l_nButtonIndex] = m_mapPTVKeys.value(l_nButtonIndex).toLower();
            }
    }
    for(int l_nButtonIndex=42;l_nButtonIndex<49;l_nButtonIndex++)

    {
        if(m_objVKeyButtons[28]->readStatus() == false){
            m_objVKeyButtons[l_nButtonIndex]->setText(m_mapPTVKeys.value(l_nButtonIndex).toUpper());
            m_mapPTVKeys[l_nButtonIndex] = m_mapPTVKeys.value(l_nButtonIndex).toUpper();
            }
        else{
            m_objVKeyButtons[l_nButtonIndex]->setText(m_mapPTVKeys.value(l_nButtonIndex).toLower());
            m_mapPTVKeys[l_nButtonIndex] = m_mapPTVKeys.value(l_nButtonIndex).toLower();
            }
    }

}

QString Widget::validateKey(QString pKey)
{
    QStringList m_strKey;
    QString l_nTempKey;
    l_nTempKey = m_strText;
    if(m_objVKeyButtons[41]->readStatus() == true)
    {
        printf("Shift Pressed\n");
    }
    else
    {
        printf("Shift Not Pressed\n");
    }
    if(pKey.length() >3 )
    {
        if(pKey.contains("Caps Lock"))
        {
            m_strText = "";
            changeKeyPad();
            return l_nTempKey;
        }
        if(pKey.contains("Shift"))
        {
            m_strText = "";
            return l_nTempKey;
        }
        if(pKey.contains("<-BKsp"))
        {

            m_strText = "";
            //ui->lineEdit->clear();
            l_nTempKey.remove(l_nTempKey.length()-1,l_nTempKey.length());
            return l_nTempKey;
        }
    }
    else if(pKey.length() ==3)
    {
        if(pKey.contains("DEL"))
        {
            m_strText = "";
            if(l_nTempKey.length()>=0)
            {
                l_nTempKey.remove(ui->lineEdit->cursorPosition(),1);
            }
            return l_nTempKey;
        }
        else
        {
            m_strKey = pKey.split(" ");
            if(m_objVKeyButtons[41]->readStatus() == true)
                return m_strKey[0];
            else
                return m_strKey[1];
        }
    }
    else
        if(m_objVKeyButtons[41]->readStatus() == true)
            return pKey.toUpper();
        else
            return pKey.toLower();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
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

void Widget::constructVirtualKeyboard()
{
    QSize l_tempSize(50,50);
    int l_nXMove=15,l_nYMove=50;
    int l_nHeight=40,l_nWidth=30;
    for(int l_nButtonIndex=0;l_nButtonIndex < m_mapPTVKeys.count();l_nButtonIndex++)
    {

        if( l_nButtonIndex == 28 ||l_nButtonIndex == 41||l_nButtonIndex == 56){
            l_nWidth=100;
            if(l_nButtonIndex == 56)
                l_nWidth = 450;
            l_tempSize.setHeight(l_nHeight);
            l_tempSize.setWidth(l_nWidth);

        }
        else if(l_nButtonIndex == 13||l_nButtonIndex == 14 || l_nButtonIndex == 40 ){
            l_nWidth = 80;
            l_tempSize.setHeight(l_nHeight);
            l_tempSize.setWidth(l_nWidth);
        }
        else if(l_nButtonIndex == 59 || l_nButtonIndex == 58 || l_nButtonIndex == 57|| l_nButtonIndex == 52 ||l_nButtonIndex == 53)
        {
            l_nWidth = 65;
            l_tempSize.setHeight(l_nHeight);
            l_tempSize.setWidth(l_nWidth);

        }
        else
        {
            l_nWidth = 50;
            l_tempSize.setHeight(l_nHeight);
            l_tempSize.setWidth(l_nWidth);

        }
       m_objVKeyButtons[l_nButtonIndex] = new QmaxButton(m_mapPTVKeys.value(l_nButtonIndex),l_tempSize,"",0,l_nButtonIndex,this);
       connect(m_objVKeyButtons[l_nButtonIndex],SIGNAL(clicked(int)),this,SLOT(buttonPressed(int)));
       m_objVKeyButtons[l_nButtonIndex]->setGeometry(l_nXMove,l_nYMove,l_nWidth,l_nHeight);

       if(l_nButtonIndex == 13 || l_nButtonIndex == 27 ||l_nButtonIndex == 40||l_nButtonIndex == 53)
       {
           l_nYMove +=42;
           l_nXMove=15;
       }
       else
       {
           l_nXMove +=l_nWidth+2;
       }

    }
    m_objVKeyButtons[14]->setDisabled(true);
    m_objVKeyButtons[14]->refresh();
    m_objVKeyButtons[40]->setDisabled(true);
    m_objVKeyButtons[40]->refresh();
    m_objVKeyButtons[52]->setDisabled(true);
    m_objVKeyButtons[52]->refresh();
    m_objVKeyButtons[54]->setDisabled(true);
    m_objVKeyButtons[54]->refresh();
    m_objVKeyButtons[55]->setDisabled(true);
    m_objVKeyButtons[55]->refresh();
    m_objVKeyButtons[57]->setDisabled(true);
    m_objVKeyButtons[57]->refresh();
    m_objVKeyButtons[58]->setDisabled(true);
    m_objVKeyButtons[58]->refresh();
    m_objVKeyButtons[59]->setDisabled(true);
    m_objVKeyButtons[59]->refresh();

}


