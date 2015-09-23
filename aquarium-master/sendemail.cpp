#include "sendemail.h"

sendEmail::sendEmail(QString address, QString messagetoRecipient)
{
    SmtpClient smtp("smtp.mail.yahoo.com", 465, SmtpClient::SslConnection);

    // We need to set the username (your email address) and password
    // for smtp authentification.

    smtp.setUser("raspberryaquarium@yahoo.com");
    smtp.setPassword("EPSIembarque");

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    EmailAddress sender("raspberryaquarium@yahoo.com", "Aquariophile");
    message.setSender(&sender);

    EmailAddress to(address, "Utilisateur");
    message.addRecipient(&to);

    message.setSubject("Email From AquaRasp");

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText(messagetoRecipient);

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    if (!smtp.connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
    }

    if (!smtp.login()) {
        qDebug() << "Failed to login!" << endl;
    }

    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
    }

    smtp.quit();
}
