#ifndef OUTIL_H
#define OUTIL_H

#include "probedata.h"
#include <QDateTime>

class Outil {
public:
    Outil();
    QStringList clearList(QStringList list);
    QStringList separateObject(QString string);
    QHash<QString, QString> createHash(QString string);
    void separateByTimestamp(long i_timestamp);
    bool testJson(ProbeData a, ProbeData b);
};

#endif
