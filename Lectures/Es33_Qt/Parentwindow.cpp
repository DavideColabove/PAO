#include<QApplication>
#include<Qfont>
#include<QPushButton>
#include<QWidget>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    // QWidget é la classe base di tutti i widget
    // Un Qwidget é un atomo di una GUI: riceve eventi dal sistema (mouse, keyboard, etc) e rappresenta
    // se stessa sullo schermo
    // Una QWidget é detenuta dal suo parent
    // Una QWidget senza parent é detta una independent window (con frame e taskbar)
    // La posizione iniziale é controllata dal sistema
    QWidget window;
    // setta il titolo
    window.setWindowTitle("I'm a QWidget");
    // ridimensionamento di window
    window.resize(200, 120);
    // quit ha come parent window, ovvero quit é figlio di window 
    // Un figlio é sempre mostrato nell'area del suo parent, per default al suo top-left corner alla
    // posizione (0,0)
    QPushButton quit("Quit", &window);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    // QWidget::setGeometry(x,y,w,h):
    // (x,y) coordinate del top-left corner in pixel
    // (w,h) base ed altezza in pixel
    quit.setGeometry(10, 40, 180, 40);
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
    // la chiamata di show() su windows chiama show() anche su tutti i figli
    window.show();
    return app.exec();
}