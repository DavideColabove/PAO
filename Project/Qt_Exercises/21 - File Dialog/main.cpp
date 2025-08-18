#include <QApplication>
#include "TextEditorWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TextEditorWidget textEditor;
    textEditor.show();

    return app.exec();
}