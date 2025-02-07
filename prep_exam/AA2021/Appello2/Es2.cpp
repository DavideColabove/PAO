#include<iostream>
#include<vector>
#include<list>

using namespace std;

list<QFrame*> fun(vector<QWidget*>& v){
    list<QFrame*> res;
    for(vector<QWidget*>::iterator it = v.begin(); it != v.end(); ++it){
        if(QLabel* ql = dynamic_cast<QLabel*>(*it)){
            ql->setLineWidth(8);
            ql->setWordWrap(false);
        }
        if(QLCDNumber* qn = dynamic_cast<QLCDNumber*>(*it))
            qn->setDigitCount(3);
        if(QFrame* qf = dynamic_cast<QFrame*>(*it)){
            if(qf && !dynamic_cast<QSplitter*>(*it))
                if(qf->heightDefault() < 10)
                    res.push_back(qf);
        }
    }
    return res;
}