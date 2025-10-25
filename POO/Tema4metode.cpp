	//meth care sterge prima nota
	//meth care sterge ultima nota
	//meth care sterge toate notele
	//meth care dubleaza ultima nota
	//meth care adauga o noua nota la sfarsitul vectorului
#include <iostream>
using namespace std;

class Student {
public:
	string nume;
	int nrNote;
	int* note;
	double buget;

	Student() {
		cout << "Apel constructor faram param\n";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	void setNrNote(int _nrNote, int* _note) {
		delete[] this->nrNote;
		if(nr)
		this->nrNote = _nrNote;

	}






};
















int main() {

	return 0;
}