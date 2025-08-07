//  eredito da QWidget, posso quindi essere un top-level widget

class MyWidget : public QWidget{
    public:
        // costruttore con argomento il QWidget parent, dove il default 0 significa top-level
        MyWidget(QWidget *parent = 0) : QWidget(parent){
            // dimensione fissa
            setFixedSize(200,120);
            // MyWidget ha un QPushButton come figlio
            // tr("Quit") marca la stringa "Quit" per possibili traduzioni runtime
            QPushButton* quit = new QPushButton(tr("Quit"), this);
            quit->setGeometry(62, 40, 75, 30);
            quit->setFont(QFont("Times", 18, QFont::Bold));
            // qApp é una variabile puntatore globale dichiarata in <QApplication> che punta all'unica
            // istanza di QApplication del programma
            connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
            // il puntatore quit é una variabile locale, e non ha campo dati
            // Qt automaticamente distrugge il QPushButton quando MyWidget é distrutta
            // Quindi MyWidget non necessita di distruttore
        }
}