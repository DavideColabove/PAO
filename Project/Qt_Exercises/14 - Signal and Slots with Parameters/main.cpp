#include <QCoreApplication>
#include <QApplication>
#include "MessageWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MessageWidget widget;
    widget.show();

    return app.exec();
}
