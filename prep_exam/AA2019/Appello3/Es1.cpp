#include<iostream>
#include<list>
#include<vector>

using namespace std;

vector<QAbstractButton*> fun(list<QWidget*>& lst, const QSize& sz, vector<const QWidget*>& w){
    vector<QAbstractButton*> res;
    for(auto it = lst.begin(); it != lst.end(); ++it){
        if(*it && (*it)->sizeHint() == sz){
            w.push_back(*it->clone());
        }
        QAbstractSlider* qas = dynamic_cast<QWidget*>(*it);
        if((*it) && !(qas) && (*it)->sizeHint() == sz){
            delete *it;
            lst.erase(it);
        }
        if(*it && (dynamic_cast<QCheckBox*>(*it) || dynamic_cast<QPushButton*>(*it))){
            QAbstractButton* qab = dynamic_cast<QAbstractButton*>(*it);
            lst.erase(it);
            res.push_back(qab);
        }
    }
    return res;
}