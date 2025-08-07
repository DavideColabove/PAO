#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget> 

// dichiarazione incompleta
class QSlider;

class LCDRange: public QWidget{
    // la macro Q_OBJECT deve essere inclusa in tutte le classi che hanno segnale e/o slot
    Q_OBJECT
    private:
        QSlider *slider;
    public:
        LCDRange(QWidget *parent=0);
        int value() const;
    // custom slot
    public slots:
        void setValue(int value);
    // custom signal
    signals:    // implicitamente protected
        // un signal é automaticamente implmentato nel MOC file
        void valueChanged(int newValue);
};
#endif