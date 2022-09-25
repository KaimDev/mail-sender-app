#include <QtCore>
#include <iostream>
#include <string>

#include "../../src/SimpleMail"

using namespace SimpleMail;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // First we need to create an SmtpClient object
    // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

    Sender smtp(QLatin1String("smtp.gmail.com"), 465, Sender::SslConnection);

    std::string email;
    std::string password;
    std::string name;
    std::string email_to;
    std::string r_name;
    std::string subject;
    std::string email_text;

    std::cout << "MailSenderApp\n" << "Created by: KaimDev\n" << std::endl;


    // We need to set the username (your email address) and password
    // for smtp authentification.

    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    std::cout << "Enter your Application Password: ";
    std::getline(std::cin, password);

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "directed for: ";
    std::getline(std::cin, email_to);

    std::cout << "Receiver name: ";
    std::getline(std::cin, r_name);

    std::cout << "Subject: ";
    std::getline(std::cin, subject);

    std::cout << "Write... \n\n\n";
    std::getline(std::cin, email_text);

    smtp.setUser(QLatin1String(email));
    smtp.setPassword(QLatin1String(password));

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;

    EmailAddress sender(QLatin1String(email.c_str()), QLatin1String(name.c_str()));
    message.setSender(sender);

    EmailAddress to(QString::fromLatin1(email_to.c_str()), QString::fromLatin1(r_name.c_str()));
    message.addTo(to);

    message.setSubject(QLatin1String(subject));

    // Now add some text to the email.
    // First we create a MimeText object.

    auto text = new MimeText;

    text->setText(QLatin1String(email_text));

    // Now add it to the mail

    message.addPart(text);

    // Now we can send the mail
    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << smtp.lastError();
        return -3;
    }

    std::cout << "\nEMAIL SENT!\n" << std::endl;

    smtp.quit();
}
