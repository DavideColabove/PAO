#ifndef JSONVIEWERWIDGET_H
#define JSONVIEWERWIDGET_H

#include <QWidget>
#include <QTableWidget>

class JsonViewerWidget : public QWidget {
    Q_OBJECT

public:
    explicit JsonViewerWidget(QWidget *parent = nullptr);

private:
    QTableWidget *tableWidget;

    void loadJson();
    void saveJson();

private slots:
    void onSaveButtonClicked();
};

#endif // JSONVIEWERWIDGET_H
