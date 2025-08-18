#include "JsonViewerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JsonViewerWidget::JsonViewerWidget(QWidget *parent) : QWidget(parent) {
    tableWidget = new QTableWidget(this);

    QPushButton *saveButton = new QPushButton("Save", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, &JsonViewerWidget::onSaveButtonClicked);

    loadJson();
}

void JsonViewerWidget::loadJson() {
    // TODO: Load people.json and populate the tableWidget
}

void JsonViewerWidget::saveJson() {
    // TODO: Save the contents of tableWidget to people.json
}

void JsonViewerWidget::onSaveButtonClicked() {
    saveJson();
}
