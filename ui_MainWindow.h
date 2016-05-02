/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGroupBox *groupBox;
    QRadioButton *normalBtn;
    QRadioButton *intervalBtn;
    QGroupBox *groupBox_2;
    QRadioButton *valueBtn;
    QRadioButton *coeffBtn;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *fIn;
    QLineEdit *xIn;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *pointIn;
    QLabel *label_5;
    QLabel *ex_x;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *computeBtn;
    QLabel *ex_f;
    QLabel *ex_res_in;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QTextBrowser *output;
    QLabel *label_2;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(622, 479);
        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 251, 81));
        normalBtn = new QRadioButton(groupBox);
        normalBtn->setObjectName(QString::fromUtf8("normalBtn"));
        normalBtn->setGeometry(QRect(10, 20, 109, 22));
        intervalBtn = new QRadioButton(groupBox);
        intervalBtn->setObjectName(QString::fromUtf8("intervalBtn"));
        intervalBtn->setGeometry(QRect(10, 40, 109, 22));
        groupBox_2 = new QGroupBox(MainWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 0, 211, 91));
        valueBtn = new QRadioButton(groupBox_2);
        valueBtn->setObjectName(QString::fromUtf8("valueBtn"));
        valueBtn->setGeometry(QRect(10, 20, 109, 22));
        coeffBtn = new QRadioButton(groupBox_2);
        coeffBtn->setObjectName(QString::fromUtf8("coeffBtn"));
        coeffBtn->setGeometry(QRect(10, 40, 109, 22));
        formLayoutWidget = new QWidget(MainWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 60, 601, 202));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        fIn = new QLineEdit(formLayoutWidget);
        fIn->setObjectName(QString::fromUtf8("fIn"));

        formLayout->setWidget(3, QFormLayout::FieldRole, fIn);

        xIn = new QLineEdit(formLayoutWidget);
        xIn->setObjectName(QString::fromUtf8("xIn"));

        formLayout->setWidget(0, QFormLayout::FieldRole, xIn);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        pointIn = new QLineEdit(formLayoutWidget);
        pointIn->setObjectName(QString::fromUtf8("pointIn"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pointIn);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        ex_x = new QLabel(formLayoutWidget);
        ex_x->setObjectName(QString::fromUtf8("ex_x"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ex_x);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        computeBtn = new QPushButton(formLayoutWidget);
        computeBtn->setObjectName(QString::fromUtf8("computeBtn"));

        formLayout->setWidget(7, QFormLayout::LabelRole, computeBtn);

        ex_f = new QLabel(formLayoutWidget);
        ex_f->setObjectName(QString::fromUtf8("ex_f"));

        formLayout->setWidget(4, QFormLayout::FieldRole, ex_f);

        ex_res_in = new QLabel(formLayoutWidget);
        ex_res_in->setObjectName(QString::fromUtf8("ex_res_in"));

        formLayout->setWidget(6, QFormLayout::FieldRole, ex_res_in);

        formLayoutWidget_2 = new QWidget(MainWindow);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 270, 601, 201));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        output = new QTextBrowser(formLayoutWidget_2);
        output->setObjectName(QString::fromUtf8("output"));
        output->setAutoFormatting(QTextEdit::AutoAll);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, output);

        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Natural Spline Value and Coefficients for Normal & Interval Arithmetic", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Arithmetics", 0, QApplication::UnicodeUTF8));
        normalBtn->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        intervalBtn->setText(QApplication::translate("MainWindow", "Interval", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
        valueBtn->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        coeffBtn->setText(QApplication::translate("MainWindow", "Coefficients", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "x:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "f:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "result in:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Example:", 0, QApplication::UnicodeUTF8));
        ex_x->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Example:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Example:", 0, QApplication::UnicodeUTF8));
        computeBtn->setText(QApplication::translate("MainWindow", "Compute", 0, QApplication::UnicodeUTF8));
        ex_f->setText(QApplication::translate("MainWindow", "f", 0, QApplication::UnicodeUTF8));
        ex_res_in->setText(QApplication::translate("MainWindow", "in", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Result:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
