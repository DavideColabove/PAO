#include<iostream>
#include<fstream>

using namespace std;

class Fallimento{};

long Fun(const ios& i){
    if(i.fail())
        throw Fallimento{};
    const ifstream* ifc = dynamic_cast<const ifstream*>(&i);
    if(!ifc)
        return -2;
    ifstream* ifnc = const_cast<ifstream*>(ifc);
    if(!ifnc->is_open())
        return -1;
    else
        return ifnc->tellg();
}

int main() {
    try {
        // Caso 1: File inesistente.
        ifstream file1("inesistente.txt");
        cout << "Caso 1: " << Fun(file1) << endl;

    } catch (const Fallimento&) {
        cout << "Caso 1: Eccezione Fallimento lanciata (file inesistente o stream non valido)." << endl;
    }

    try {
        // Caso 2: File esistente, ma non aperto.
        ifstream file2;
        cout << "Caso 2: " << Fun(file2) << endl;

    } catch (const Fallimento&) {
        cout << "Caso 2: Eccezione Fallimento lanciata (stream non valido)." << endl;
    }

    try {
        // Caso 3: File esistente e aperto.
        ofstream tempFile("esempio.txt"); // Creazione di un file temporaneo.
        tempFile << "Prova di testo nel file.";
        tempFile.close();

        ifstream file3("esempio.txt");
        cout << "Caso 3: Posizione del file pointer: " << Fun(file3) << endl;
        file3.close();

    } catch (const Fallimento&) {
        cout << "Caso 3: Eccezione Fallimento lanciata." << endl;
    }

    return 0;
}