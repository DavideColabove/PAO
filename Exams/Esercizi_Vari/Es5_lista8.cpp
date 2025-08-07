#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

class C{
    private:
        vector<ios*> v;
        int max_v;
    public:
        C(int k = 1): max_v(k <= 0 ? 1 : k){}
        void insert(ios& s){
            if(v.size() < max_v){
                if(!(dynamic_cast<fstream*>(&s) || dynamic_cast<stringstream*>(&s)))
                    v.push_back(&s);
            }
        }
        template<class T>
        int conta(T& t) const{
            int count = 0;
            for(const auto it:v){
                if(dynamic_cast<T*>(it))
                    count++;
            }
            return count;
        }
};

int main() {
    ifstream f("pippo"); ofstream g("mandrake");
    fstream h("pluto"), i("zagor");
    ostream* p = &g;
    stringstream s;
    C c(10);
    c.insert(f); c.insert(g); c.insert(h); c.insert(i); c.insert(*p); c.insert(s);
    istream& r=f;
    cout << c.conta(r); // stampa: 1 (e‘ il puntatore all’oggetto f)
}