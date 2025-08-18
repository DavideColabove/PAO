#include <QApplication>
#include <QTabWidget>
#include "CounterButtonInheritance.h"
#include "CounterWidgetComposition.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QTabWidget tabWidget;

    // TODO: Create an instance of CounterButtonInheritance and add it to the first tab
    // TODO: Create an instance of CounterWidgetComposition and add it to the second tab

    tabWidget.show();

    return app.exec();
}
