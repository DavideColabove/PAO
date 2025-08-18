#include "Contact.h"

Contact::Contact(const QString &name, const QString &email, const QString &phone)
    : m_name(name), m_email(email), m_phone(phone) {}

QString Contact::name() const { return m_name; }
QString Contact::email() const { return m_email; }
QString Contact::phone() const { return m_phone; }

void Contact::setName(const QString &name) { m_name = name; }
void Contact::setEmail(const QString &email) { m_email = email; }
void Contact::setPhone(const QString &phone) { m_phone = phone; }
