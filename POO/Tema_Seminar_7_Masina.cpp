#include <iostream>
using namespace std;

class Masina {
private:
    const string VIN;
    string nrInmatriculare;
    int anFabricatie;
    static string* VINuri;
    static string* numere;
    static int nrMasini;
    static int mem;

    static void alocaMemorie() {

        int nouaMem;
        if (mem == 0) {
            nouaMem = 1;
        }
        else {
            nouaMem = mem + 1;
        }

        string* VINnou = new string[nouaMem];
        string* numereNoi = new string[nouaMem];

        if (VINuri != nullptr && numere != nullptr) {
            for (int i = 0; i < nrMasini; i++) {
                VINnou[i] = VINuri[i];
                numereNoi[i] = numere[i];
            }
        }

        delete[] VINuri;
        delete[] numere;

        VINuri = VINnou;
        numere = numereNoi;
        mem = nouaMem;
    }

public:
    Masina(string _VIN, string _nrInmatriculare, int _anFabricatie) : VIN(_VIN) {

        if (nrMasini == mem) {
            alocaMemorie();
        }

        bool exista = false;
        bool existaNumar = false;

        for (int i = 0; i < nrMasini; i++) {
            if (VINuri[i] == _VIN) {
                exista = true;
            }

            if (numere[i] == _nrInmatriculare) {
                existaNumar = true;
            }
        }

        if (exista) {
            cout << "\nVIN-ul exista deja!!!";
        }
         if (existaNumar){
            cout << "\nNr exista deja!!!";
        }
        if(!exista && !existaNumar) {
            VINuri[nrMasini] = _VIN;
            numere[nrMasini] = _nrInmatriculare;
            nrMasini++;
        }


        if (_nrInmatriculare.length() == 9) {
            this->nrInmatriculare = _nrInmatriculare;
        }
        else {
            this->nrInmatriculare = "na";
        }

        if (_anFabricatie > 1900) {
            this->anFabricatie = _anFabricatie;
        }
        else {
            this->anFabricatie = 0;
        }
    }

    void setNrInmatriculare(string _nrNou) {
        if (_nrNou.length() != 9) {
            return;
        }
        for (int i = 0; i < nrMasini; i++) {
            if (numere[i] == _nrNou) {
                cout << "\nNumarul exista deja";
                return;
            }
        }
        bool gasit = false;
        for (int i = 0; i < nrMasini; i++) {
            if (numere[i] == this->nrInmatriculare) {
                numere[i] = _nrNou;
                gasit = true;
                break;
            }
        }
            if (gasit) {
                this->nrInmatriculare = _nrNou;
            }
            else {
                cout << "\nNu s-a putut actualiza";
            }
    }

    /*static bool esteDisponibil(string _nr) {
        if (_nr.length() == 9) {
            for (int i = 0; i < nrMasini; i++) {
                if (numere[i] == _nr) {
                    return false;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }*/

    void afisare() {
        cout << "\nVIN: " << this->VIN;
        cout << "\nNr inmatriculare: " << this->nrInmatriculare;
        cout << "\nAn: " << this->anFabricatie;
        cout << "\n";
    }

    friend void esteDisponibil(string _nr);
};

void esteDisponibil(string _nr) {
    bool esteGasit = false;

    for (int i = 0; i < Masina::nrMasini; i++) {
        if (Masina::numere[i] == _nr) {
            esteGasit = true; 
            break;
        }
    }

    if (esteGasit == true) {
        cout << "\nNu este disponibil";
    }
    else {
        cout << "\nEste disponibil";
    }
}

string* Masina::VINuri = nullptr;
string* Masina::numere = nullptr;
int Masina::nrMasini = 0;
int Masina::mem = 0;

int main() {
    Masina m1("0000", "B 222 AAA", 2009);
    m1.afisare();

    Masina m2("00001", "B 223 AAA", 2009);
    m2.afisare();

    m2.setNrInmatriculare("B 224 AAA");
    m2.afisare();

    esteDisponibil("B 229 AAA");


    return 0;
}