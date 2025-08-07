#include<iostream>
#include<list>
#include<vector>

using namespace std;

list<QCheckBox> Fun(vector<const QWidget*>& v, const QSize& s){
    list<QCheckBox> res;
    for(auto it = v.begin(); it != v.end(); ++it){
        QAbstractSlider* qas = dynamic_cast<QAbstractSlider*>(const_cast<QAbstractSlider*>(*it));
        if(qas){
            if(!(dynamic_cast<QSlider*>(qas))){
                delete qas;
                qas = new QSlider(dynamic_cast<QSlider*>(qas));
                qs->resize(s);
            }
            QSlider* qsl = dynamic_cast<QSlider*>((qas));
            else if(qsl && qsl->size() != s){
                qsl->resize(s);
                qsl->setSliderDown(true);
            }
        }
        QAbstractButton* q ab = dynamic_cast<QAbstractButton*>(const_cast<QAbstractButton>(*it));
        else if(qab && qab->isDown()){
            if(QCheckBox* qcb = dynamic_cast<QCheckBox*>(qab))
                res.push_back(*qcb);
            delete qab;
            it = v.erase(it);
            --it;
        }
    }
    return res;
}