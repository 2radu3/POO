#include <iostream>
using namespace std;
//acasa sa facem tips and tricks minimul de supravietuit
//shallow si deep copy
class Student {
	string nume; //char* nume; char nume[21];
	int nrNote;
	int* note;
	double buget;
	
public:
	//constructori
	//constructori cu parametrii

	Student() //ca sa fie constructor trebuie sa aiba numele clasei
	{
		cout << "\nApel constructor fara param";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;

	}

	Student(double _buget) //ce primim ca parametru punem _
	{
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	Student(string _nume, int _nrNote, int* _note, double _buget)
	{
		if (_nume.length()>=2) {
			this->nume = _nume;
		}
		else {
			this->nume = "Anonim";
		}

		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			//v1 (shallow copy)
			this->note = _note;
			//v2 (deep copy)
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}

		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	//meth de prelucrate -> afisare

	void afisare() /*daca punem const aici protejam obiectul de la adresa this*/ {
		cout << "\nNume: " << this->nume;
		cout << "\nNumar note: " << this-> nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
		cout << "\nBuget: " << this->buget;
	}

	//meth accesor (get si set)

	void setNrNote(int _nrNote, int* _note) {
		//to do home
		//!!!!obj this deja exista
	}

	void setNota(int _nota, int _index) {
		//to do home
		//plus validari
		//modifica nota
	}

	int getNota(int _index) {
		//to do home
		return 0;
	}

	int getNrNote(int _index) {
		//to do home
		return 0;
	}

	//meth prelucrare
	//meth care sterge prima nota
	//meth care sterge ultima nota
	//meth care sterge toate notele
	//meth care dubleaza ultima nota
	//meth care adauga o noua nota la sfarsitul vectorului
	//clasa despre masina care ii stiu cap rezervorului, cap curenta, si un vector de alimentari si o metoda care sa 
	//consume combustibilul, consum mediu optional
	//vectorul de alimenatare 5l, 10l 3l, cat am pus

	//supraincarcare de operatori

	//destructor
};


int main()
{
	Student s1;
	s1.afisare();
	Student* s2; //pointer la sudent, 4 bytes, nu se apeleaza niciun constructor
	s2 = new Student(); //apelul constructorului fara param
	s2 = new Student[5]; //un vector alocat dinamic de student, se apeleaza de 5 ori constructorul default
	s2 = new Student; //echivalentul liniei 84
	Student s3[5]; //un vector alocat static de obiecte de tip student, se apeleaza de 5 ori constructorul default, sizeof=5*cat ocupa student
	Student* s4[5]; //vector de pointeri alocat static de student*, sizeof = 4*5/8*5 
	Student** s5; //pointer la pointer la student, sizeof 4/8, poate sa devina un vector alocat dinamic de pointer la student, poate sa devina
				  //o matrice, mai merge lucrat
	Student s6(2); //se apeleaza constructorul cu un parametru
	Student s7 = 2; //acelasi lucru ca cel de mai sus
	Student s8(); //nu este un obiect de tip student, este o functie
 /* s.afisare();
	cout << s;
	s.adaugaNota();
	s += 9; */


	return 0;
}