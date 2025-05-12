/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *Network_Interfaces;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textInterfaces;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *editIP;
    QLabel *label_3;
    QLineEdit *editSubnet;
    QLabel *label;
    QComboBox *comboInterface;
    QPushButton *btnApply;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnActivate;
    QPushButton *btnDeactivate;
    QLabel *label_4;
    QComboBox *comboActivateDeactivate;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1051, 803);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Network_Interfaces = new QGroupBox(centralwidget);
        Network_Interfaces->setObjectName(QString::fromUtf8("Network_Interfaces"));
        Network_Interfaces->setGeometry(QRect(70, 20, 321, 251));
        horizontalLayout = new QHBoxLayout(Network_Interfaces);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textInterfaces = new QTextBrowser(Network_Interfaces);
        textInterfaces->setObjectName(QString::fromUtf8("textInterfaces"));

        horizontalLayout->addWidget(textInterfaces);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(510, 30, 341, 247));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        editIP = new QLineEdit(groupBox);
        editIP->setObjectName(QString::fromUtf8("editIP"));

        verticalLayout->addWidget(editIP);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        editSubnet = new QLineEdit(groupBox);
        editSubnet->setObjectName(QString::fromUtf8("editSubnet"));

        verticalLayout->addWidget(editSubnet);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboInterface = new QComboBox(groupBox);
        comboInterface->setObjectName(QString::fromUtf8("comboInterface"));

        verticalLayout->addWidget(comboInterface);

        btnApply = new QPushButton(groupBox);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));

        verticalLayout->addWidget(btnApply);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 340, 951, 81));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnActivate = new QPushButton(groupBox_2);
        btnActivate->setObjectName(QString::fromUtf8("btnActivate"));

        horizontalLayout_3->addWidget(btnActivate);

        btnDeactivate = new QPushButton(groupBox_2);
        btnDeactivate->setObjectName(QString::fromUtf8("btnDeactivate"));

        horizontalLayout_3->addWidget(btnDeactivate);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        comboActivateDeactivate = new QComboBox(groupBox_2);
        comboActivateDeactivate->setObjectName(QString::fromUtf8("comboActivateDeactivate"));

        horizontalLayout_3->addWidget(comboActivateDeactivate);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1051, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Network_Interfaces->setTitle(QCoreApplication::translate("MainWindow", "Network Interfaces", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Modify IP Address", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "IP Address:", nullptr));
        editIP->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g., 192.168.1.100", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Subnet Mask:", nullptr));
        editSubnet->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g., 255.255.255.0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Interface Name:", nullptr));
        comboInterface->setPlaceholderText(QCoreApplication::translate("MainWindow", "eth0", nullptr));
        btnApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Activate/Deactivate Interface", nullptr));
        btnActivate->setText(QCoreApplication::translate("MainWindow", "Activate", nullptr));
        btnDeactivate->setText(QCoreApplication::translate("MainWindow", "Deactivate", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Interface Name:", nullptr));
        comboActivateDeactivate->setPlaceholderText(QCoreApplication::translate("MainWindow", "eth0 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
