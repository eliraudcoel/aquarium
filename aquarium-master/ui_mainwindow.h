/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Accueil;
    QLabel *label_welcome;
    QWidget *Live;
    QWidget *HistoTempe;
    QCustomPlot *TempPlot;
    QGroupBox *groupBoxTempe;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *temperature_slider;
    QLabel *label_temp;
    QPushButton *btn_ph;
    QPushButton *btn_light;
    QWidget *HistoPH;
    QCustomPlot *PhPlot;
    QGroupBox *groupBox_PH;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *ph_slider;
    QLabel *label_ph;
    QPushButton *btn_ph_2;
    QPushButton *btn_light_2;
    QWidget *Parametres;
    QGroupBox *parametre_min_ph;
    QLabel *label_7;
    QLabel *label_9;
    QSlider *temperature_min;
    QLabel *label_temp_min;
    QDoubleSpinBox *ph_min;
    QGroupBox *parametre_max_ph;
    QLabel *label_8;
    QLabel *label_10;
    QSlider *temperature_max;
    QLabel *label_temp_max;
    QDoubleSpinBox *PH_max;
    QGroupBox *parametre_max_ph_2;
    QLabel *label_15;
    QCheckBox *checkBoxNotification;
    QPushButton *ValidationEmail;
    QLabel *AlerteEmail;
    QLineEdit *email;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(694, 366);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(-5, -4, 701, 351));
        Accueil = new QWidget();
        Accueil->setObjectName(QStringLiteral("Accueil"));
        label_welcome = new QLabel(Accueil);
        label_welcome->setObjectName(QStringLiteral("label_welcome"));
        label_welcome->setGeometry(QRect(300, 10, 181, 31));
        tabWidget->addTab(Accueil, QString());
        Live = new QWidget();
        Live->setObjectName(QStringLiteral("Live"));
        tabWidget->addTab(Live, QString());
        HistoTempe = new QWidget();
        HistoTempe->setObjectName(QStringLiteral("HistoTempe"));
        TempPlot = new QCustomPlot(HistoTempe);
        TempPlot->setObjectName(QStringLiteral("TempPlot"));
        TempPlot->setGeometry(QRect(39, 29, 621, 141));
        groupBoxTempe = new QGroupBox(HistoTempe);
        groupBoxTempe->setObjectName(QStringLiteral("groupBoxTempe"));
        groupBoxTempe->setGeometry(QRect(40, 180, 621, 121));
        label = new QLabel(groupBoxTempe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 91, 21));
        label_2 = new QLabel(groupBoxTempe);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 91, 21));
        label_3 = new QLabel(groupBoxTempe);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 60, 91, 21));
        temperature_slider = new QSlider(groupBoxTempe);
        temperature_slider->setObjectName(QStringLiteral("temperature_slider"));
        temperature_slider->setGeometry(QRect(140, 40, 160, 19));
        temperature_slider->setOrientation(Qt::Horizontal);
        label_temp = new QLabel(groupBoxTempe);
        label_temp->setObjectName(QStringLiteral("label_temp"));
        label_temp->setGeometry(QRect(180, 20, 61, 15));
        btn_ph = new QPushButton(groupBoxTempe);
        btn_ph->setObjectName(QStringLiteral("btn_ph"));
        btn_ph->setGeometry(QRect(170, 80, 92, 27));
        btn_light = new QPushButton(groupBoxTempe);
        btn_light->setObjectName(QStringLiteral("btn_light"));
        btn_light->setGeometry(QRect(470, 60, 92, 27));
        tabWidget->addTab(HistoTempe, QString());
        HistoPH = new QWidget();
        HistoPH->setObjectName(QStringLiteral("HistoPH"));
        PhPlot = new QCustomPlot(HistoPH);
        PhPlot->setObjectName(QStringLiteral("PhPlot"));
        PhPlot->setGeometry(QRect(50, 20, 621, 141));
        groupBox_PH = new QGroupBox(HistoPH);
        groupBox_PH->setObjectName(QStringLiteral("groupBox_PH"));
        groupBox_PH->setGeometry(QRect(51, 171, 621, 121));
        label_4 = new QLabel(groupBox_PH);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 40, 91, 21));
        label_5 = new QLabel(groupBox_PH);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 80, 91, 21));
        label_6 = new QLabel(groupBox_PH);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(380, 60, 91, 21));
        ph_slider = new QSlider(groupBox_PH);
        ph_slider->setObjectName(QStringLiteral("ph_slider"));
        ph_slider->setGeometry(QRect(140, 40, 160, 19));
        ph_slider->setOrientation(Qt::Horizontal);
        label_ph = new QLabel(groupBox_PH);
        label_ph->setObjectName(QStringLiteral("label_ph"));
        label_ph->setGeometry(QRect(180, 20, 61, 15));
        btn_ph_2 = new QPushButton(groupBox_PH);
        btn_ph_2->setObjectName(QStringLiteral("btn_ph_2"));
        btn_ph_2->setGeometry(QRect(170, 80, 92, 27));
        btn_light_2 = new QPushButton(groupBox_PH);
        btn_light_2->setObjectName(QStringLiteral("btn_light_2"));
        btn_light_2->setGeometry(QRect(470, 60, 92, 27));
        tabWidget->addTab(HistoPH, QString());
        Parametres = new QWidget();
        Parametres->setObjectName(QStringLiteral("Parametres"));
        parametre_min_ph = new QGroupBox(Parametres);
        parametre_min_ph->setObjectName(QStringLiteral("parametre_min_ph"));
        parametre_min_ph->setGeometry(QRect(20, 20, 621, 71));
        label_7 = new QLabel(parametre_min_ph);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 40, 91, 21));
        label_9 = new QLabel(parametre_min_ph);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(370, 40, 91, 21));
        temperature_min = new QSlider(parametre_min_ph);
        temperature_min->setObjectName(QStringLiteral("temperature_min"));
        temperature_min->setGeometry(QRect(140, 40, 160, 19));
        temperature_min->setOrientation(Qt::Horizontal);
        label_temp_min = new QLabel(parametre_min_ph);
        label_temp_min->setObjectName(QStringLiteral("label_temp_min"));
        label_temp_min->setGeometry(QRect(180, 20, 61, 15));
        ph_min = new QDoubleSpinBox(parametre_min_ph);
        ph_min->setObjectName(QStringLiteral("ph_min"));
        ph_min->setGeometry(QRect(480, 40, 62, 22));
        parametre_max_ph = new QGroupBox(Parametres);
        parametre_max_ph->setObjectName(QStringLiteral("parametre_max_ph"));
        parametre_max_ph->setGeometry(QRect(20, 100, 621, 81));
        label_8 = new QLabel(parametre_max_ph);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 40, 91, 21));
        label_10 = new QLabel(parametre_max_ph);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(370, 40, 91, 21));
        temperature_max = new QSlider(parametre_max_ph);
        temperature_max->setObjectName(QStringLiteral("temperature_max"));
        temperature_max->setGeometry(QRect(140, 40, 160, 19));
        temperature_max->setMinimum(3);
        temperature_max->setTracking(true);
        temperature_max->setOrientation(Qt::Horizontal);
        label_temp_max = new QLabel(parametre_max_ph);
        label_temp_max->setObjectName(QStringLiteral("label_temp_max"));
        label_temp_max->setGeometry(QRect(180, 20, 61, 15));
        PH_max = new QDoubleSpinBox(parametre_max_ph);
        PH_max->setObjectName(QStringLiteral("PH_max"));
        PH_max->setGeometry(QRect(480, 40, 62, 22));
        parametre_max_ph_2 = new QGroupBox(Parametres);
        parametre_max_ph_2->setObjectName(QStringLiteral("parametre_max_ph_2"));
        parametre_max_ph_2->setGeometry(QRect(20, 200, 621, 111));
        label_15 = new QLabel(parametre_max_ph_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 60, 91, 21));
        checkBoxNotification = new QCheckBox(parametre_max_ph_2);
        checkBoxNotification->setObjectName(QStringLiteral("checkBoxNotification"));
        checkBoxNotification->setGeometry(QRect(50, 20, 431, 17));
        ValidationEmail = new QPushButton(parametre_max_ph_2);
        ValidationEmail->setObjectName(QStringLiteral("ValidationEmail"));
        ValidationEmail->setGeometry(QRect(530, 60, 75, 23));
        AlerteEmail = new QLabel(parametre_max_ph_2);
        AlerteEmail->setObjectName(QStringLiteral("AlerteEmail"));
        AlerteEmail->setGeometry(QRect(270, 90, 251, 16));
        email = new QLineEdit(parametre_max_ph_2);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(130, 60, 331, 20));
        tabWidget->addTab(Parametres, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>ee</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_welcome->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(Accueil), QApplication::translate("MainWindow", "Accueil", 0));
        tabWidget->setTabText(tabWidget->indexOf(Live), QApplication::translate("MainWindow", "Live", 0));
        groupBoxTempe->setTitle(QApplication::translate("MainWindow", "Actions", 0));
        label->setText(QApplication::translate("MainWindow", "Temp\303\251rature", 0));
        label_2->setText(QApplication::translate("MainWindow", "Ajout de pH", 0));
        label_3->setText(QApplication::translate("MainWindow", "Lumi\303\250re", 0));
        label_temp->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        btn_ph->setText(QApplication::translate("MainWindow", "On", 0));
        btn_light->setText(QApplication::translate("MainWindow", "On", 0));
        tabWidget->setTabText(tabWidget->indexOf(HistoTempe), QApplication::translate("MainWindow", "Historique temp\303\251rature", 0));
        groupBox_PH->setTitle(QApplication::translate("MainWindow", "Actions", 0));
        label_4->setText(QApplication::translate("MainWindow", "Ph", 0));
        label_5->setText(QApplication::translate("MainWindow", "Ajout de pH", 0));
        label_6->setText(QApplication::translate("MainWindow", "Lumi\303\250re", 0));
        label_ph->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        btn_ph_2->setText(QApplication::translate("MainWindow", "On", 0));
        btn_light_2->setText(QApplication::translate("MainWindow", "On", 0));
        tabWidget->setTabText(tabWidget->indexOf(HistoPH), QApplication::translate("MainWindow", "Historique PH", 0));
        parametre_min_ph->setTitle(QApplication::translate("MainWindow", "Valeurs minimum", 0));
        label_7->setText(QApplication::translate("MainWindow", "Temp\303\251rature", 0));
        label_9->setText(QApplication::translate("MainWindow", "PH", 0));
        label_temp_min->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        parametre_max_ph->setTitle(QApplication::translate("MainWindow", "Valeurs maximum", 0));
        label_8->setText(QApplication::translate("MainWindow", "Temp\303\251rature", 0));
        label_10->setText(QApplication::translate("MainWindow", "PH", 0));
        label_temp_max->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        parametre_max_ph_2->setTitle(QApplication::translate("MainWindow", "Configuration alertes", 0));
        label_15->setText(QApplication::translate("MainWindow", "Email", 0));
        checkBoxNotification->setText(QApplication::translate("MainWindow", "Autoriser l'envoi d'email de notification en cas de valeurs minimum/maximum atteintes", 0));
        ValidationEmail->setText(QApplication::translate("MainWindow", "OK", 0));
        AlerteEmail->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(Parametres), QApplication::translate("MainWindow", "Param\303\250tres", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
