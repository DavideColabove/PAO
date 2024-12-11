#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    // costruisce il pulsante con una label
    QPushButton quit("Quit");
    // ridimensiona il pulsante quit
    quit.resize(75,30);
    // setta la font del pulsante quit
    quit.setFont(QFont("Times", 18, QFont::Bold));
    // invocazione di connect(), metodo statico di QObject
    // stabilisce una connesione tra due QObject
    // Ogni QObject (e quindi ogni QWidget) puó avere signal (mandare messaggi) e slot (ricevere messaggi)
    // Il segnale clicked di quit é connesso allo slot quit() di app:"
    // quando si clicka il pulsante quit l'applicazione app termina
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
    quit.show();
    return QApplication::exec();
}