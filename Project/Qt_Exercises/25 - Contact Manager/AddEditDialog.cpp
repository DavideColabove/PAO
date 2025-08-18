#include "AddEditDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

AddEditDialog::AddEditDialog(QWidget *parent) : QDialog(parent) {
    nameEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    phoneEdit = new QLineEdit(this);

    QPushButton *okButton = new QPushButton("OK", this);
    QPushButton *cancelButton = new QPushButton("Cancel", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Name:"));
    layout->addWidget(nameEdit);
    layout->addWidget(new QLabel("Email:"));
    layout->addWidget(emailEdit);
    layout->addWidget(new QLabel("Phone:"));
    layout->addWidget(phoneEdit);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    connect(okButton, &QPushButton::clicked, this, &AddEditDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AddEditDialog::reject);
}

QString AddEditDialog::getName() const { return nameEdit->text(); }

void AddEditDialog::setName(QString name) {
    // TODO: Set content of the line edit
}

QString AddEditDialog::getEmail() const { return emailEdit->text(); }

void AddEditDialog::setEmail(QString email) {
    // TODO: Set content of the line edit
}

QString AddEditDialog::getPhone() const { return phoneEdit->text(); }

void AddEditDialog::setPhone(QString phone) {
    // TODO: Set content of the line edit
}

void AddEditDialog::accept() {
    if (nameEdit->text().isEmpty() || emailEdit->text().isEmpty() || phoneEdit->text().isEmpty()) {
        // TODO: Show an error message if any field is empty
        return;
    }
    QDialog::accept();
}
