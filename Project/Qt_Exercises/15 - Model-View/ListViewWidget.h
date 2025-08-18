#ifndef LISTVIEWWIDGET_H
#define LISTVIEWWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include <QVBoxLayout>

class ListViewWidget : public QWidget {
    Q_OBJECT

public:
    explicit ListViewWidget(QWidget *parent = nullptr);

private slots:
    void addItem();
    
    void removeItem();

private:
    QListView *listView;
    QLineEdit *lineEdit;
    QPushButton *addButton;
    QPushButton *removeButton;
    QStringListModel *model;
};

#endif // LISTVIEWWIDGET_H
