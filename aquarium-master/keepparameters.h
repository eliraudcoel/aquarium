#ifndef KEEPPARAMETERS_H
#define KEEPPARAMETERS_H


#include <QStringList>
#include <QFile>
#include <QDomDocument>
#include <iostream>
#include <QDir>
#include <QDebug>

class keepParameters
{
public:
    keepParameters();

    //Get parameters
    QString getEmail();
    bool getAuthorizationNotification();
    double getPhMin();
    double getPhMax();
    int getTemperatureMin();
    int getTemperatureMax();

    //Set parameters
    void setEmail(QString email);
    void setAuthorizationNotification(QString auth);
    void setPhMin(double phmin);
    void setPhMax(double phmax);
    void setTemperatureMin(int tempmin);
    void setTemperatureMax(int tempmax);

private:
    QDomDocument *doc_parameters;
    QFile *file_parameters;
};

#endif // KEEPPARAMETERS_H
