#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QString>
#include "../../SmtpClient/src/SmtpMime"

class sendEmail
{
public:
    sendEmail(QString address,QString message);
};

#endif // SENDEMAIL_H
