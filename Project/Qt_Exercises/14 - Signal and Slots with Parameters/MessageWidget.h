#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class MessageWidget : public QWidget {
    Q_OBJECT

public:
    explicit MessageWidget(QWidget *parent = nullptr);

private slots:
    void updateLabel();

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *button;
};

#endif // MESSAGEWIDGET_H
