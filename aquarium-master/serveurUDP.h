#ifndef SERVEURUDP_H
#define SERVEURUDP_H

#include <QtWidgets>
#include <QtNetwork>
#include <QUdpSocket>
#include <QString>
#include <QFile>
#include <QDateTime>
#include "outil.h"
#include "keepparameters.h"
#include "sendemail.h"

class ServeurUDP : public QObject
{
    Q_OBJECT

public:
    ServeurUDP(QObject *parent = 0);
    QUdpSocket *socket;
    QByteArray currentBuffer;
    QList<ProbeData> currentListPh;
    QList<ProbeData> currentListTemp;

private slots:
    void traitementMessage();

private:
    Q_DISABLE_COPY(ServeurUDP)
    Outil outil;
    void savePhData(QString data);
    void saveTempData(QString data);
    void dispatchData();
    bool isTempData(ProbeData *probe_data);
    bool isPhData(ProbeData *probe_data);

};
#endif // SERVEURUDP_H
