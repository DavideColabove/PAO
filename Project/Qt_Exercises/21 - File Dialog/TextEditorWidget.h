#ifndef TEXTEDITORWIDGET_H
#define TEXTEDITORWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class TextEditorWidget : public QWidget {
    Q_OBJECT

public:
    explicit TextEditorWidget(QWidget *parent = nullptr);

private:
    QTextEdit *textEdit;
    QPushButton *openButton;
    QPushButton *saveButton;

    void setupUI();

private slots:
    void openFile();
    void saveFile();
};

#endif // TEXTEDITORWIDGET_H
