#include <QApplication>
#include "StyledWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StyledWidget styledWidget;
    styledWidget.show();

    return app.exec();
}
