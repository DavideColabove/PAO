#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>
#include <QLineEdit>

class AddEditDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddEditDialog(QWidget *parent = nullptr);
    QString getName() const;
    void setName(QString name);
    QString getEmail() const;
    void setEmail(QString email);
    QString getPhone() const;
    void setPhone(QString phone);

private:
    QLineEdit *nameEdit;
    QLineEdit *emailEdit;
    QLineEdit *phoneEdit;

private slots:
    // TODO: Implement the accept method and validation logic for the dialog
    void accept() override;
};

#endif // ADDEDITDIALOG_H
