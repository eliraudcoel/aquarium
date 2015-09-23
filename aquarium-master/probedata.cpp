#include "probedata.h"

ProbeData::ProbeData(QHash<QString, QString> hash) {
    this->setType(hash.value("Type"));
    this->setValue(hash.value("Value").toFloat());
    this->setTimestamp(hash.value("Timestamp").toLong());
    this->setIdRasp(hash.value("IdRasp").toInt());
}

void ProbeData::displayProbeData() {
    qDebug() << "TYPE : " << this->getType();
    qDebug() << "VALUE : " << this->getValue();
    qDebug() << "TIMESTAMP : " << this->getTimestamp();
    qDebug() << "IDRASP : " << this->getIdRasp();
}

void ProbeData::setType(QString type) {
    this->type = type;
}

QString ProbeData::getType() {
    return this->type;
}

void ProbeData::setValue(float value) {
    this->value = value;
}

float ProbeData::getValue() {
    return this->value;
}

void ProbeData::setTimestamp(long timestamp) {
    this->timestamp = timestamp;
}

long ProbeData::getTimestamp() {
    return this->timestamp;
}

void ProbeData::setIdRasp(int idRasp) {
    this->idRasp = idRasp;
}

int ProbeData::getIdRasp() {
    return this->idRasp;
}

QString ProbeData::toStringJson() {
    QString data_str = QString("{Type:\"%1\", Value:%2, Timestamp:%3, IdRasp:%4}")
            .arg(this->getType())
            .arg(this->getValue())
            .arg(this->getTimestamp())
            .arg(this->getIdRasp());

    return data_str;
}
