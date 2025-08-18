#include <QApplication>
#include "ImageDisplayWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImageDisplayWidget widget;
    widget.show();

    return app.exec();
}
