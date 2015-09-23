#include "serveurUDP.h"
#include "mainwindow.h"

#define SOCKET_PORT 9999
#define PH_FILES_PATH "C:/Users/amorc_000/Documents/CoursI4/Qt/aquariumFinalWithSMTP/aquarium-master/data/ph/"
#define TEMP_FILES_PATH "C:/Users/amorc_000/Documents/CoursI4/Qt/aquariumFinalWithSMTP/aquarium-master/data/temp/"

ServeurUDP::ServeurUDP(QObject *parent) : QObject(parent) {
    socket = new QUdpSocket();
    socket->bind(SOCKET_PORT, QUdpSocket::ShareAddress);

    connect(socket, SIGNAL(readyRead()), this, SLOT(traitementMessage()));
}

void ServeurUDP::traitementMessage() {
    while (socket->hasPendingDatagrams()) { // Tant qu'il y a des messages
        QByteArray buf; // buffer de lecture
        buf.resize(socket->pendingDatagramSize());
        socket->readDatagram(buf.data(), buf.size());

        currentBuffer = buf;

        dispatchData();
    }
}

void ServeurUDP::savePhData(QString data) {
    QDateTime currentDate = QDateTime::currentDateTime();
    QString date_str = currentDate.toString("dd-MM-yyyy");

    QString current_ph_path = PH_FILES_PATH + date_str + ".txt";

    QFile current_ph_file(current_ph_path);

    current_ph_file.open(QIODevice::ReadWrite | QIODevice::Append);

    if(!current_ph_file.isOpen()){
        qDebug() << "Impossible d'ouvrir le fichier : " << current_ph_path;
    } else {
        QTextStream outStream(&current_ph_file);
        qDebug() << data;
        outStream << data + ",";

        current_ph_file.close();
    }
}

void ServeurUDP::saveTempData(QString data) {
    QDateTime currentDate = QDateTime::currentDateTime();
    QString date_str = currentDate.toString("dd-MM-yyyy");

    QString current_temp_path = TEMP_FILES_PATH + date_str + ".txt";
    QFile current_temp_file(current_temp_path);

    current_temp_file.open(QIODevice::ReadWrite | QIODevice::Append);

    if(!current_temp_file.isOpen()){
        qDebug() << "Impossible d'ouvrir le fichier : " << current_temp_path;
    } else {
        QTextStream outStream(&current_temp_file);
        outStream << data + ",";

        current_temp_file.close();
    }
}

void ServeurUDP::dispatchData() {
    QString data_str = QString::fromUtf8(currentBuffer.data());
    keepParameters parameters;
    if (!data_str.isNull() && !data_str.isEmpty()) {
        QStringList list = outil.separateObject(data_str);

        for (int var2 = 0; var2 < list.length(); ++var2) {
            QHash<QString, QString> hash = outil.createHash(list[var2]);
            ProbeData probeData = ProbeData(hash);
            QDateTime timestamp;

            //Association de la date en seconde à l'objet date
            timestamp.setTime_t( probeData.getTimestamp());

            if(isTempData(&probeData) == true) {
                currentListTemp << probeData;
                if(probeData.getValue()> parameters.getTemperatureMax())
                {
                    QString Temphigh = "Temperature est trop haute  " + QString::number(probeData.getValue()) + ". Date : " +  timestamp.toString(Qt::SystemLocaleShortDate);
                    sendEmail(parameters.getEmail(), Temphigh);
                }
                else if(probeData.getValue()<parameters.getTemperatureMin())
                {
                    QString TempLow = "Temperature est trop basse  " + QString::number(probeData.getValue()) + ". Date : " +  timestamp.toString(Qt::SystemLocaleShortDate);
                    sendEmail(parameters.getEmail(), TempLow);
                }

                saveTempData(probeData.toStringJson());
            } else {
                currentListPh << probeData;

                if(probeData.getValue()> parameters.getPhMax())
                {
                    QString PHhigh = "PH est trop haut  " + QString::number(probeData.getValue()) + ". Date : " + timestamp.toString(Qt::SystemLocaleShortDate);
                    sendEmail(parameters.getEmail(), PHhigh);
                }
                else if(probeData.getValue()<parameters.getPhMin())
                {
                    QString PHlow = "PH est trop bas : " + QString::number(probeData.getValue()) + ". Date : " + timestamp.toString(Qt::SystemLocaleShortDate);
                    sendEmail(parameters.getEmail(), PHlow);
                }
                savePhData(probeData.toStringJson());
            }
        }
    }
}

bool ServeurUDP::isTempData(ProbeData *probe_data) {
    return probe_data->getType() == "temp";
}

bool ServeurUDP::isPhData(ProbeData *probe_data) {
    return probe_data->getType() == "ph";
}
