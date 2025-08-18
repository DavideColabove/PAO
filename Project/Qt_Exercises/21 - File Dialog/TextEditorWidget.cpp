#include "TextEditorWidget.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

TextEditorWidget::TextEditorWidget(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void TextEditorWidget::setupUI() {
    textEdit = new QTextEdit(this);
    openButton = new QPushButton("Open", this);
    saveButton = new QPushButton("Save", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->addWidget(openButton);
    layout->addWidget(saveButton);

    connect(openButton, &QPushButton::clicked, this, &TextEditorWidget::openFile);
    connect(saveButton, &QPushButton::clicked, this, &TextEditorWidget::saveFile);
}

void TextEditorWidget::openFile() {
    // TODO: Use QFileDialog to select a file and load its content into textEdit
}

void TextEditorWidget::saveFile() {
    // TODO: Use QFileDialog to select a location and save textEdit content to a file
}
