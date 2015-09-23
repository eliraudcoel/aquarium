#include "keepparameters.h"

using namespace std;

keepParameters::keepParameters()
{
    doc_parameters=new QDomDocument("parameters_document");
    file_parameters=new QFile("parameters.xml");
}


//Get parameters
QString keepParameters::getEmail()
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"getEmail error";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();

    QDomNodeList nodeList =  docParameters.elementsByTagName("email");

    QString email;

    if(nodeList.count()>0)
    {
        for(int iDx = 0;iDx < nodeList.count(); iDx++)
        {
            email = nodeList.at(iDx).attributes().namedItem("address").nodeValue();
        }
    }

    return email;
}

bool keepParameters::getAuthorizationNotification()
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("email");

    bool auth;

    if(nodeList.count()>0)
    {
        for(int iDx = 0;iDx < nodeList.count(); iDx++)
        {
            if(nodeList.at(iDx).attributes().namedItem("notification").nodeValue().toLower()=="yes")
                auth=1;
            else
                auth=0;
        }
    }
    return auth;
}

double keepParameters::getPhMin()
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        qDebug() << "getph Erreur " << file_parameters->errorString();

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("PH");

    double PhMin;
    qDebug() << nodeList.count();

    if(nodeList.count()>0)
    {
        for(int iDx = 0;iDx < nodeList.count(); iDx++)
        {
            PhMin= nodeList.at(iDx).attributes().namedItem("min").nodeValue().toDouble();
            qDebug() << "phmin" << PhMin;
        }
    }

    return PhMin;

}

double keepParameters::getPhMax()
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("PH");

    double PhMax;

    if(nodeList.count()>0)
    {
        for(int iDx = 0;iDx < nodeList.count(); iDx++)
        {
            PhMax= nodeList.at(iDx).attributes().namedItem("max").nodeValue().toDouble();
        }
    }

    return PhMax;
}

int keepParameters::getTemperatureMin()
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("Temperature");

    int tempMin;

    if(nodeList.count()>0)
    {
        for(int iDx = 0;iDx < nodeList.count(); iDx++)
        {
            tempMin= nodeList.at(iDx).attributes().namedItem("min").nodeValue().toDouble();
        }
    }

    return tempMin;

}

int keepParameters::getTemperatureMax()
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("Temperature");

    int tempMax;

    if(nodeList.count()>0)
    {
        for(int iDx = 0;iDx < nodeList.count(); iDx++)
        {
            tempMax= nodeList.at(iDx).attributes().namedItem("max").nodeValue().toDouble();
        }
    }

    return tempMax;

}


//Set parameters
void keepParameters::setEmail(QString email)
{
    qDebug() << __FUNCTION__ << "()";
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("email");

    QDomElement setemail = nodeList.at(0).toElement();
    setemail.setAttribute("address",email);

    if (!file_parameters->open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        qDebug() << "Basically, now we lost content of a file";
    }
    QByteArray xml = doc_parameters->toByteArray();
    file_parameters->write(xml);
    file_parameters->close();

}

void keepParameters::setAuthorizationNotification(QString auth)
{
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("email");

    QDomElement setNotification = nodeList.at(0).toElement();
    setNotification.setAttribute("notification",auth);

    if (!file_parameters->open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        qDebug() << "Basically, now we lost content of a file";
    }
    QByteArray xml = doc_parameters->toByteArray();
    file_parameters->write(xml);
    file_parameters->close();

}

void keepParameters::setPhMin(double phmin)
{
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("PH");

    QDomElement setPhMin = nodeList.at(0).toElement();
    setPhMin.setAttribute("min",phmin);


    if (!file_parameters->open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        qDebug() << "Basically, now we lost content of a file";
    }
    QByteArray xml = doc_parameters->toByteArray();
    file_parameters->write(xml);
    file_parameters->close();

}

void keepParameters::setPhMax(double phmax)
{
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("PH");

    QDomElement setPhMin = nodeList.at(0).toElement();
    setPhMin.setAttribute("max",phmax);

    if (!file_parameters->open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        qDebug() << "Basically, now we lost content of a file";
    }
    QByteArray xml = doc_parameters->toByteArray();
    file_parameters->write(xml);
    file_parameters->close();

}

void keepParameters::setTemperatureMin(int tempmin)
{
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("Temperature");

    QDomElement setPhMin = nodeList.at(0).toElement();
    setPhMin.setAttribute("min",tempmin);

    if (!file_parameters->open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        qDebug() << "Basically, now we lost content of a file";
    }
    QByteArray xml = doc_parameters->toByteArray();
    file_parameters->write(xml);
    file_parameters->close();
}

void keepParameters::setTemperatureMax(int tempmax)
{
    if (!file_parameters->open(QIODevice::ReadOnly))
        cout<<"Erreur";

    if (!doc_parameters->setContent(file_parameters))
    {
        file_parameters->close();
        //cout<<"Erreur setContent local ";
    }
    file_parameters->close();
    QDomElement docParameters = doc_parameters->documentElement();
    QDomNodeList nodeList =  docParameters.elementsByTagName("Temperature");

    QDomElement setPhMin = nodeList.at(0).toElement();
    setPhMin.setAttribute("max",tempmax);

    if (!file_parameters->open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        qDebug() << "Basically, now we lost content of a file";
    }
    QByteArray xml = doc_parameters->toByteArray();
    file_parameters->write(xml);
    file_parameters->close();

}
