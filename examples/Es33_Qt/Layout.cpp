class MyWidget : public QWidget {
    public:
        MyWidget(QWidget *partent = 0): QWidget(parent){
            QPushButton *quit = new QPushButton(tr("Quit"));
            quit->setFont(QFont("Times", 18, QFont::Bold));
            // QLCDNumber é un widget che mostre i numeri come un LCD
            QLCDNumber *lcd = new QLCDNumber(2);    // 2 cifre
            // rende lcd piú leggibile
            lcd->setSegmentStyle(QLCDNumber::Filled);
            // Il widget QSlider permette di selezionare un valore intero in un range
            // slider é un QSlider orizzontale con valori in [0,99], e valore iniziale 0
            QSlider *slider = new QSlider(Qt::Horizontal);
            slider->setRange(0,99);
            slider->setValue(0);
            connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
            // segnale valueChanged(int) di slider connesso allo slot display(int) di lcd slider
            // emette il segnale valueChanged() quando cambia il suo valore 
            //lo slot é quindi chiamato quando viene emesso questo segnale
            connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
            // QVBoxLayout é un layout manager (LM) che gestisce la geometria di piazzamento dei figli
            // di un widget; inoltre il LM di un widget w gestisce il ridimensionamento dei figli di w
            // quando viene ridimensionato w 
            // QLayout non é sottotipo di QWidget, quindi LM non ha mai un parent
            QVBoxLayout *layout = new QVBoxLayout;
            // layout->addWidget() aggiunge dei widget al LM layout
            layout->addWidget(quit);
            layout->addWidget(lcd);
            layout->addWidget(slider);
            // QWidget::setLayout(layout) installa layout come LM di this
            // inoltre rende layout un figlio di this, e tutti i widget in layout diventano figli di this
            setLayout(layout);
        }
};