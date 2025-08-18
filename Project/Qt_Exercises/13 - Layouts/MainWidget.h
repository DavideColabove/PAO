#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

private slots:
    void updateLabel();

private:
    QLabel *label;
    QPushButton *button;
};

#endif // MAINWIDGET_H
