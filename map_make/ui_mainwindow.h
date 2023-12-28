/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionhe;
    QAction *full;
    QWidget *centralwidget;
    QPushButton *block_view;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        actionhe = new QAction(MainWindow);
        actionhe->setObjectName(QString::fromUtf8("actionhe"));
        full = new QAction(MainWindow);
        full->setObjectName(QString::fromUtf8("full"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        block_view = new QPushButton(centralwidget);
        block_view->setObjectName(QString::fromUtf8("block_view"));
        block_view->setGeometry(QRect(300, 0, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionopen);
        menu->addAction(actionsave);
        menu_2->addAction(full);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        actionhe->setText(QCoreApplication::translate("MainWindow", "he", nullptr));
        full->setText(QCoreApplication::translate("MainWindow", "full", nullptr));
        block_view->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\217\221\350\200\205\346\250\241\345\274\217", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "tool", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
