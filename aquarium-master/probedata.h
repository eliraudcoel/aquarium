#ifndef PROBEDATA_H
#define PROBEDATA_H

#include <QHash>
#include <string>
#include <QDebug>
#include <QObject>

class ProbeData {

public:
    ProbeData(QHash<QString, QString> hash);
    void displayProbeData();

    QString getType();
    void setType(QString type);

    float getValue();
    void setValue(float value);

    long getTimestamp();
    void setTimestamp(long timestamp);

    int getIdRasp();
    void setIdRasp(int idRasp);

    QString toStringJson();

private:
    QString type;
    float value;
    long timestamp;
    int idRasp;
};

#endif // PROBEDATA_H
