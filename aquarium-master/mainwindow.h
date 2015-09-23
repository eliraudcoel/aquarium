#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"
#include "keepparameters.h"
#include "serveurUDP.h"
#include "sendemail.h"


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ServeurUDP *serveur;

private:
    Ui::MainWindow *ui;
    QString userEmail;
    float phMax;
    float phMin;
    int tempMin;
    int tempMax;
    keepParameters *parameters;

private slots :
    void afficherTemperature(int temp);
    void afficherPh(int ph);
    void changeButtonPh();
    void changeButtonLight();
    void changeButtonPh_ph();
    void changeButtonLight_ph();
    void getPhMax(double phmax);
    void getPhMin(double phmin);
    void getTempMax(int tempMax);
    void getTempMin(int tempMin);
    void afficherTempMin(int tempmin);
    void afficherTempMax(int tempmax);
    void getEmail();
    void getNotification();
    void updateGraphOnUI();

};

#endif // MAINWINDOW_H
