#ifndef STYLEDWIDGET_H
#define STYLEDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class StyledWidget : public QWidget {
    Q_OBJECT

public:
    explicit StyledWidget(QWidget *parent = nullptr);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *button;

    void setupUI();
};

#endif // STYLEDWIDGET_H
