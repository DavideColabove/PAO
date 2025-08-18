#include <QCoreApplication>
#include <QApplication>
#include "MainWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWidget mainWidget;
    mainWidget.show();

    return app.exec();
}
