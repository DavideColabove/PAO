#include<vector>
#include<string>

using namespace std;

vector<QWidget> fun(const vector<const QPaintDevice*>& v){
    vector<QWidget> copia;
    for(auto p:v){
        const QWidget* qp = dynamic_cast<const QWidget*>(p);
        const QAbstractButton* qa = dynamic_cast<const QAbstractButton*>(p);
        if(qp){
            if(qp->height() > 50)
                throw Qstring("TooBig");
            if(qp->hasFocus())
                QPaintDevice* nqp = const_cast<Qwidget*>(qp);
                nqp->clearFocus();
        }
        else if(qa){
            QAbstractButton* nqa = const_cast<QAbstractButton*>(qa);
            nqa->setText("Pulsante");
        }
        else if(qp && !qa){
            copia.push_back(*qp);
        }
        delete qp;
        delete qa;
        delete nqp;
        delete nqa;
    }
    return copia;
}