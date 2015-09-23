#include "outil.h"

Outil::Outil(){}

// On retire les éléments non gérés
QStringList Outil::clearList(QStringList list) {
    for (int var = 0; var < list.size(); ++var) {
        list[var].replace("{","");
        list[var].replace("}","");
        list[var].replace("[","");
        list[var].replace("]","");
        list[var].replace("\n","");
        list[var].replace("\"","");
    }

    return list;
}

// On découpe le Json par élément
QStringList Outil::separateObject(QString string) {
    QStringList list;

    list = string.split("},{");
    list = clearList(list);

    return list;
}

// Création d'un Hash d'élement tiré du JSON
QHash<QString, QString> Outil::createHash(QString string) {
    QHash<QString, QString> hash;
    QString regexp_element(",");
    QString regexp_key_value(":");

    QStringList miniHash = string.split(regexp_element);

    for (int var = 0; var < miniHash.size(); ++var) {
        QStringList values = miniHash[var].split(regexp_key_value);

        hash.insert(values[0], values[1]);
    }

    return hash;
}

// Découpage par Timestamp
void Outil::separateByTimestamp(long i_timestamp) {
    //Creation de l'objet QDateTime qui va se charger de convertir
    QDateTime timestamp;

    //Association de la date en seconde à l'objet date
    timestamp.setTime_t(i_timestamp);

    //Afficher le resultat (pour le test seulement)
    qDebug() << "Date : " << timestamp.toString(Qt::SystemLocaleShortDate);
}

bool Outil::testJson(ProbeData a, ProbeData b) {
    return (a.getTimestamp() < b.getTimestamp());
}
