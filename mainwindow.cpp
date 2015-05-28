#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_temp->setText("0°C");

    connect(ui->temperature_slider, SIGNAL(valueChanged(int)), this, SLOT(afficherTemperature(int)));
    connect(ui->btn_ph, SIGNAL(clicked()), this, SLOT(changeButtonPh()));
    connect(ui->btn_light, SIGNAL(clicked()), this, SLOT(changeButtonLight()));
}

void MainWindow::afficherTemperature(int temp) {
    QString temperature = QString::number(temp);
    ui->label_temp->setText(temperature + "°C");
}

void MainWindow::changeButtonPh() {
    if (ui->btn_ph->text() == "On") {
        ui->btn_ph->setText("Off");
    } else
        ui->btn_ph->setText("On");
}
void MainWindow::changeButtonLight() {
    if (ui->btn_light->text() == "On") {
        ui->btn_light->setText("Off");
    } else
        ui->btn_light->setText("On");
}

MainWindow::~MainWindow()
{
    delete ui;
}
