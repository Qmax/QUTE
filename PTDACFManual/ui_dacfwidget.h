/********************************************************************************
** Form generated from reading UI file 'dacfwidget.ui'
**
** Created: Tue Sep 30 16:24:49 2014
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DACFWIDGET_H
#define UI_DACFWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DACFWidget
{
public:
    QPushButton *butSave;
    QPushButton *butExit;
    QComboBox *cmgRanges;
    QLabel *lblRanges;
    QLabel *lblOffset;
    QLineEdit *leOffset;
    QTableWidget *tableWidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;

    void setupUi(QWidget *DACFWidget)
    {
        if (DACFWidget->objectName().isEmpty())
            DACFWidget->setObjectName(QString::fromUtf8("DACFWidget"));
        DACFWidget->resize(258, 400);
        butSave = new QPushButton(DACFWidget);
        butSave->setObjectName(QString::fromUtf8("butSave"));
        butSave->setGeometry(QRect(19, 340, 110, 40));
        butSave->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
""));
        butExit = new QPushButton(DACFWidget);
        butExit->setObjectName(QString::fromUtf8("butExit"));
        butExit->setGeometry(QRect(130, 340, 110, 40));
        butExit->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
""));
        cmgRanges = new QComboBox(DACFWidget);
        cmgRanges->setObjectName(QString::fromUtf8("cmgRanges"));
        cmgRanges->setGeometry(QRect(131, 20, 110, 40));
        cmgRanges->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:1px solid gray;\n"
" }"));
        lblRanges = new QLabel(DACFWidget);
        lblRanges->setObjectName(QString::fromUtf8("lblRanges"));
        lblRanges->setGeometry(QRect(20, 20, 110, 40));
        lblRanges->setStyleSheet(QString::fromUtf8("border:1px solid gray;"));
        lblOffset = new QLabel(DACFWidget);
        lblOffset->setObjectName(QString::fromUtf8("lblOffset"));
        lblOffset->setGeometry(QRect(20, 70, 110, 40));
        lblOffset->setStyleSheet(QString::fromUtf8("border:1px solid gray;"));
        leOffset = new QLineEdit(DACFWidget);
        leOffset->setObjectName(QString::fromUtf8("leOffset"));
        leOffset->setGeometry(QRect(131, 70, 110, 40));
        leOffset->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
""));
        tableWidget = new QTableWidget(DACFWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 130, 194, 186));
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        tableWidget->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
""));
        tableWidget->setFrameShape(QFrame::Box);
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setGridStyle(Qt::DotLine);
        line = new QFrame(DACFWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 0, 5, 400));
        line->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(DACFWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(253, 0, 5, 400));
        line_2->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(DACFWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(3, 395, 253, 5));
        line_3->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(DACFWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(2, 0, 253, 5));
        line_4->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        retranslateUi(DACFWidget);

        QMetaObject::connectSlotsByName(DACFWidget);
    } // setupUi

    void retranslateUi(QWidget *DACFWidget)
    {
        DACFWidget->setWindowTitle(QApplication::translate("DACFWidget", "DACFWidget", 0, QApplication::UnicodeUTF8));
        butSave->setText(QApplication::translate("DACFWidget", "SAVE", 0, QApplication::UnicodeUTF8));
        butExit->setText(QApplication::translate("DACFWidget", "EXIT", 0, QApplication::UnicodeUTF8));
        cmgRanges->clear();
        cmgRanges->insertItems(0, QStringList()
         << QApplication::translate("DACFWidget", "0.6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACFWidget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACFWidget", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACFWidget", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DACFWidget", "14", 0, QApplication::UnicodeUTF8)
        );
        lblRanges->setText(QApplication::translate("DACFWidget", "Select Range :", 0, QApplication::UnicodeUTF8));
        lblOffset->setText(QApplication::translate("DACFWidget", "Offset Value:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DACFWidget", "  Offset", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("DACFWidget", "0.6     ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("DACFWidget", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("DACFWidget", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("DACFWidget", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("DACFWidget", "14", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class DACFWidget: public Ui_DACFWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DACFWIDGET_H
