#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QJsonArray>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QListWidget *contactListWidget;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QPushButton *loadButton;

    void setupUI();
    void loadContacts(const QString &filePath);
    void saveContacts(const QString &filePath);

private slots:
    // TODO: Implement slot to add a contact
    void addContact();

    // TODO: Implement slot to edit a contact
    void editContact();

    // TODO: Implement slot to delete a contact
    void deleteContact();

    // TODO: Implement slot to save contacts to a file
    void saveContactsToFile();

    // TODO: Implement slot to load contacts from a file
    void loadContactsFromFile();
};

#endif // MAINWINDOW_H
