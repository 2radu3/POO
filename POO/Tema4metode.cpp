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
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	void setNrNote(int _nrNote, int* _note) {
		delete[] this->note;
		if (_nrNote > 0 && _note != nullptr)
		{
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
			{
				this->note[i] = _note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}

	}

	int getNrNote() {
		return nrNote;
	}

	int* getNote() {
		return note;
	}

	void stergePrimaNota() {
		int* notenoi = new int[this->nrNote - 1];
		for (int i = 1; i < this->nrNote; i++)
			notenoi[i - 1]=note[i];
		delete[] this->note;
		this->nrNote = this->nrNote - 1;
		this->note = notenoi;
	}



};

int main() {

	Student s1;
	int noteint[] = { 2, 3, 4, 5 };
	int nrnote = sizeof(noteint) / sizeof(noteint[0]);
	
	
	s1.setNrNote(nrnote, noteint);
	cout << "Numar note: " << s1.getNrNote();

	int* note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";


	s1.stergePrimaNota();
	cout << "\nNumar note: " << s1.getNrNote();

	note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";

	

	return 0;
}