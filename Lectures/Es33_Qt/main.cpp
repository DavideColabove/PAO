// inclusione di header files

#include <QApplication>
#include <QPushButton>
using namespace std;

int main(int argc, char *argv[]) {
    // una QApplication in ogni Qt GUI
    // argc e argv sono passati al costruttore di QApplication
    QApplication a(argc, argv);
    // QPushButton é un widget 
    // costruzione del QPushButton hello
    // hello non ha parent window, lui stesso é una window con frame e title bar
    QPushButton hello("Hello World!");
    // show() é uno slot, rende visisbile un widget, che altrimenti non é visibile 
    hello.show();
    // main() passa il controllo a Qtinvocando il metodo statico exec()
    return QApplication::exec();
}
