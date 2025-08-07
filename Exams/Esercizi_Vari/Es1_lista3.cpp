#include<iostream>
#include<string>
#include<vector>

using namespace std;
using std::string;
using std::ostream;

template<class T>
class Dizionario;
template<class T>
class Elemento{
    friend class Dizionario<T>;
    template <class U>
    friend ostream& operator<<(ostream&, const Dizionario<U>&);
    private:
        string chiave;
        T valore;
};

template<class T>
class Dizionario{
    template <class U>
    friend ostream& operator<<(ostream&, const Dizionario<U>&);
    private: 
        vector<Elemento<T>> dati;
    public:
        bool insert(string chiave, const T& valore){
            for(auto v:dati){
                if(v.chiave == chiave)
                    return false;
            }
            Elemento<T> e;
            e.chiave = chiave;
            e.valore = valore;
            dati.push_back(e);
            return true;
        }
        bool erase(const string chiave){
            for(auto it = dati.cbegin(); it != dati.cend(); ++it){
                if(it->chiave == chiave){
                    if(it != dati.end()){
                        dati.erase(it);
                        return true;
                    }
                }
            }
            return false;
        }
        T* findValue(const string chiave){
            for(auto& v:dati){
                if(v.chiave == chiave){
                    return &v.valore;
                }
            }
            return nullptr;
        }
        vector<string> findKey(const T& valore){
            vector<string> chiavi;
            for(const auto v:dati){
                if(v.valore == valore){
                    chiavi.push_back(v.chiave);
                }
            }
            return chiavi;
        }
        T& operator[](const string chiave){
            return *findValue(chiave);
        }
};

template<class U>
ostream& operator<<(ostream& os, const Dizionario<U>& d){
    for(auto v:d.dati){
        os << v.chiave << ":  " << v.valore << endl;
    }
    return os;
}

int main() {
    Dizionario<int> diz;

    // Inserimento di coppie chiave-valore
    diz.insert("uno", 1);
    diz.insert("due", 2);
    diz.insert("tre", 3);

    // Stampa il dizionario
    cout << "Dizionario dopo gli inserimenti:" << endl;
    cout << diz << endl;

    // Tentativo di inserire una chiave esistente
    if (!diz.insert("due", 22)) {
        cout << "La chiave 'due' esiste gia'!" << endl;
    }

    // Ricerca di un valore
    int* valore = diz.findValue("due");
    if (valore) {
        cout << "Valore associato alla chiave 'due': " << *valore << endl;
    } else {
        cout << "Chiave 'due' non trovata." << endl;
    }

    // Ricerca di chiavi associate a un valore
    vector<string> chiavi = diz.findKey(3);
    cout << "Chiavi associate al valore 3:" << endl;
    for (const auto& chiave : chiavi) {
        cout << chiave << endl;
    }

    // Operatore di indicizzazione
    cout << "Modifico il valore della chiave 'tre'..." << endl;
    diz["tre"] = 33;
    cout << "Nuovo valore della chiave 'tre': " << diz["tre"] << endl;

    // Rimuovere una chiave
    if (diz.erase("uno")) {
        cout << "Chiave 'uno' rimossa con successo." << endl;
    } else {
        cout << "Chiave 'uno' non trovata." << endl;
    }

    // Stampa finale del dizionario
    cout << "Dizionario finale:" << endl;
    cout << diz << endl;

    return 0;
}