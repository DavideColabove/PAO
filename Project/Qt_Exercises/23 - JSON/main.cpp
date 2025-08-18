#include <QApplication>
#include "JsonViewerWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    JsonViewerWidget jsonViewer;
    jsonViewer.show();

    return app.exec();
}
