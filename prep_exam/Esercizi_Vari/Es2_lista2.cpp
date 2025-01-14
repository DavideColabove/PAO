#include<iostream>
using std::cout;

class It {
    friend class C;
    public:
        bool operator<(It i) {return index < i.index;}
        It operator++(int) { It t = *this; index++; return t; }
        It operator+(int k) {index = index + k; return *this; }
    private:
        int index;
};

class C {
    public:
        C(int k) {
            if (k>0) {dim=k; p = new int[k];}
            for(int i=0; i<k; i++) *(p+i)=i;
        }
        It begin() { It t; t.index = 0; return t; }
        It end() { It t; t.index = dim; return t; }
        int& operator[](It i) {return *(p + i.index);}
    private:
        int* p;
        int dim;
};

main() {
    C c1(4), c2(8);
    for(It i = c1.begin(); i < c1.end(); i++) 
        cout << c1[i] << ' ';
                                cout << "UNO\n";
    It i = c2.begin();
    for(int n=0; i < c2.end(); ++n, i = i+n) 
        cout << c2[i] << ' ';
                                cout << "DUE\n";
}