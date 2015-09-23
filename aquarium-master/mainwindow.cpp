#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QByteArray>
#include <QFile>
#include <QFileInfo>

#include <iostream>
#include <string>
#include <QDebug>

#include <QRegExp>

#include <QDateTime>

QString onString = "On";
QString offString = "Off";
QString phString = "ph";
QString tempString = "temp";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    serveur = new ServeurUDP();

    parameters = new keepParameters();

    ui->setupUi(this);


    //Initialisation des différents widgets Onglet historique température et PH
    ui->label_temp->setText(QString::number((parameters->getTemperatureMin()+parameters->getTemperatureMax())/2));
    ui->label_ph->setText(QString::number((parameters->getPhMin()+parameters->getPhMax())/2));

    ui->ph_slider->setMinimum(parameters->getPhMin());
    ui->ph_slider->setMaximum(parameters->getPhMax());
    ui->temperature_slider->setMinimum(parameters->getTemperatureMin());
    ui->temperature_slider->setMaximum(parameters->getTemperatureMax());

    ui->ph_slider->setValue((parameters->getPhMin()+parameters->getPhMax())/2);
    ui->temperature_slider->setValue((parameters->getTemperatureMin()+parameters->getTemperatureMax())/2);


    //Initialisation des différents widgets Onglet Paramètre
    ui->temperature_max->setValue(parameters->getTemperatureMax());
    ui->temperature_min->setValue(parameters->getTemperatureMin());
    ui->PH_max->setValue(parameters->getPhMax());
    ui->ph_min->setValue(parameters->getPhMin());

    ui->label_temp_max->setText(QString::number(parameters->getTemperatureMax()));
    ui->label_temp_min->setText(QString::number(parameters->getTemperatureMin()));

    ui->checkBoxNotification->setChecked(parameters->getAuthorizationNotification());

    ui->AlerteEmail->setText("");

    //Initialisation Accueil
    ui->label_welcome->setText("Bienvenue " + parameters->getEmail() + "!");

    connect(ui->temperature_slider, SIGNAL(valueChanged(int)), this, SLOT(afficherTemperature(int)));
    connect(ui->btn_ph, SIGNAL(clicked()), this, SLOT(changeButtonPh()));
    connect(ui->btn_light, SIGNAL(clicked()), this, SLOT(changeButtonLight()));

    connect(ui->ph_slider, SIGNAL(valueChanged(int)), this, SLOT(afficherPh(int)));
    connect(ui->btn_ph_2, SIGNAL(clicked()), this, SLOT(changeButtonPh_ph()));
    connect(ui->btn_light_2, SIGNAL(clicked()), this, SLOT(changeButtonLight_ph()));

    // Récupération Email
    connect(ui->ValidationEmail, SIGNAL(clicked()), this, SLOT(getEmail()));

    // Affichage temp Max et Min choisies
    connect(ui->temperature_max, SIGNAL(valueChanged(int)), this, SLOT(afficherTempMax(int)));
    connect(ui->temperature_min, SIGNAL(valueChanged(int)), this, SLOT(afficherTempMin(int)));


    // Récupération valeur maximum et minimum
    connect(ui->PH_max, SIGNAL(valueChanged(double)), this, SLOT(getPhMax(double)));
    connect(ui->ph_min, SIGNAL(valueChanged(double)), this, SLOT(getPhMin(double)));
    connect(ui->temperature_max, SIGNAL(valueChanged(int)), this, SLOT(getTempMax(int)));
    connect(ui->temperature_min, SIGNAL(valueChanged(int)), this, SLOT(getTempMin(int)));

    // Récupération de la valeur notification pour l'envoi d'email
    connect(ui->checkBoxNotification,SIGNAL(clicked()), this, SLOT(getNotification()));

    // Connexion de la lecture de la socket à la fonction updateGraphOnUI
    connect(serveur->socket, SIGNAL(readyRead()), this, SLOT(updateGraphOnUI()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getEmail() {
    if(ui->email->text()!="") {
        userEmail = ui->email->text();
        ui->AlerteEmail->hide();
        ui->label_welcome->setText("Bienvenue : " + userEmail + "!");
        sendEmail(userEmail, "Send test for raspberryaquarium@yahoo.com");
        parameters->setEmail(userEmail);
    } else {
        ui->AlerteEmail->setStyleSheet("QLabel { color : red; }");
        ui->AlerteEmail->setText("Aucun email rentré");
    }
}

void MainWindow::getNotification() {
    bool checked = ui->checkBoxNotification->isChecked();
    if(checked)
        parameters->setAuthorizationNotification("yes");
    else
        parameters->setAuthorizationNotification("no");

}

void MainWindow::afficherTempMax(int tempmax) {
    QString afficheTempMax = QString::number(tempmax);
    ui->label_temp_max->setText(afficheTempMax);
}

void MainWindow::afficherTempMin(int tempmin) {
    QString afficheTempMin = QString::number(tempmin);
    ui->label_temp_min->setText(afficheTempMin);
}

void MainWindow::getPhMax(double phmax) {
    parameters->setPhMax(phmax);
    ui->ph_slider->setMaximum(phmax);
}

void MainWindow::getPhMin(double phmin) {
    parameters->setPhMin(phmin);
    ui->ph_slider->setMinimum(phmin);
}

void MainWindow::getTempMax(int tempmax) {
    parameters->setTemperatureMax(tempmax);
    ui->temperature_slider->setMaximum(tempmax);
}

void MainWindow::getTempMin(int tempmin) {
    parameters->setTemperatureMin(tempmin);
    ui->temperature_slider->setMinimum(tempmin);

}

void MainWindow::afficherPh(int ph) {
    QString affichePh = QString::number(ph);
    ui->label_ph->setText(affichePh);
}

void MainWindow::afficherTemperature(int temp) {
    QString temperature = QString::number(temp);
    ui->label_temp->setText(temperature + "°C");
}

void MainWindow::changeButtonPh() {
    if (ui->btn_ph->text() == onString) {
        ui->btn_ph->setText(offString);
    } else
        ui->btn_ph->setText(onString);
}
void MainWindow::changeButtonLight() {
    if (ui->btn_light->text() == onString) {
        ui->btn_light->setText(offString);
    } else
        ui->btn_light->setText(onString);
}
void MainWindow::changeButtonPh_ph() {
    if (ui->btn_ph_2->text() == onString) {
        ui->btn_ph_2->setText(offString);
    } else
        ui->btn_ph_2->setText(onString);
}
void MainWindow::changeButtonLight_ph() {
    if (ui->btn_light_2->text() == onString) {
        ui->btn_light_2->setText(offString);
    } else
        ui->btn_light_2->setText(onString);
}

// Méthode générale de construction de graphe
void makeGraph(QCustomPlot *graph, int max, QList<ProbeData> data, QString label) {
    QVector<double> times(1440), values(1440); // 1440 minutes = 24h

    for (int var = 0; var < data.length(); ++var) {
        times[var] = data[var].getTimestamp();
        values[var] = data[var].getValue();
        if(data[var].getValue() > max) max = data[var].getValue();
    }

    graph->addGraph();
    graph->graph(0)->setData(times, values);

    graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    graph->xAxis->setDateTimeFormat("HH:MM:ss");
    graph->xAxis->setLabel("date"); //x
    graph->xAxis->setRange(data.first().getTimestamp(), data.last().getTimestamp());

    graph->yAxis->setLabel(label); //y
    graph->yAxis->setRange(0, max);

    graph->replot();
}

// Méthode de construction d'un graphe PH
void makePhGraph(Ui::MainWindow *ui, ServeurUDP *serveur) {
    QList<ProbeData> phData = serveur->currentListPh;

    if(phData.size() > 0) {
        int max = phData.first().getValue();
        QCustomPlot *ph_plot = ui->PhPlot;

        makeGraph(ph_plot, max, phData, phString);
    }
}

// Méthode de construction d'un graphe Température
void makeTempGraph(Ui::MainWindow *ui, ServeurUDP *serveur) {
    QList<ProbeData> tempData = serveur->currentListTemp;
    if(tempData.size() > 0) {
        int max = tempData.first().getValue();
        QCustomPlot *temp_plot = ui->TempPlot;

        makeGraph(temp_plot, max, tempData, tempString);
    }
}

// Mis à jour des graphes PH et Température
void MainWindow::updateGraphOnUI() {
    makePhGraph(ui, serveur);
    makeTempGraph(ui, serveur);
}
