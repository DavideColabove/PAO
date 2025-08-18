#include "MainWindow.h"
#include "AddEditDialog.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void MainWindow::setupUI() {
    contactListWidget = new QListWidget(this);
    addButton = new QPushButton("Add Contact", this);
    editButton = new QPushButton("Edit Contact", this);
    deleteButton = new QPushButton("Delete Contact", this);
    saveButton = new QPushButton("Save Contacts", this);
    loadButton = new QPushButton("Load Contacts", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(contactListWidget);
    layout->addWidget(addButton);
    layout->addWidget(editButton);
    layout->addWidget(deleteButton);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addContact);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::editContact);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteContact);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveContactsToFile);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadContactsFromFile);
}

void MainWindow::addContact() {
    // TODO: Implement logic to open AddEditDialog and add a new contact to the list
}

void MainWindow::editContact() {
    // TODO: Implement logic to edit the selected contact in the contact list
}

void MainWindow::deleteContact() {
    QListWidgetItem *item = contactListWidget->currentItem();
    if (item) {
        // TODO: Delete the selected contact from the list
    } else {
        // TODO: Show an error message if no contact is selected
    }
}

void MainWindow::saveContactsToFile() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save Contacts", "", "JSON Files (*.json)");
    if (!filePath.isEmpty()) {
        // TODO: Save contacts to the chosen file path
    }
}

void MainWindow::loadContactsFromFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open Contacts", "", "JSON Files (*.json)");
    if (!filePath.isEmpty()) {
        // TODO: Load contacts from the chosen file path
    }
}

void MainWindow::saveContacts(const QString &filePath) {
    // TODO: Serialize the contact list to a QJsonArray and save it to the file
}

void MainWindow::loadContacts(const QString &filePath) {
    // TODO: Read the JSON file and load the contacts into the contact list widget
}
