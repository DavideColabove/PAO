#include <QApplication>
#include "XmlViewerWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    XmlViewerWidget xmlViewer;
    xmlViewer.show();

    return app.exec();
}
