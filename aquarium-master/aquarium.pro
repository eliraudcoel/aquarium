#-------------------------------------------------
#
# Project created by QtCreator 2015-08-09T13:28:36
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport network

TARGET = aquarium
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    keepparameters.cpp \
    probedata.cpp \
    outil.cpp \
    serveurUDP.cpp \
    sendemail.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    keepparameters.h \
    probedata.h \
    serveurUDP.h \
    outil.h \
    sendemail.h

FORMS    += mainwindow.ui

# Location of SMTP Library
SMTP_LIBRARY_LOCATION = ../../build-SMTPEmail-Debug

win32:CONFIG(release, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$SMTP_LIBRARY_LOCATION/debug/ -lSMTPEmail
else:unix: LIBS += -L$$SMTP_LIBRARY_LOCATION -lSMTPEmail

INCLUDEPATH += $$SMTP_LIBRARY_LOCATION
DEPENDPATH += $$SMTP_LIBRARY_LOCATION
