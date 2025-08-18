#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
public:
    Contact(const QString &name, const QString &email, const QString &phone);

    QString name() const;
    QString email() const;
    QString phone() const;

    void setName(const QString &name);
    void setEmail(const QString &email);
    void setPhone(const QString &phone);

private:
    QString m_name;
    QString m_email;
    QString m_phone;
};

#endif // CONTACT_H
