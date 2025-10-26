//clasa masina despre care ii stiu cap rezervorului, cap curenta, un vector de alimentari si o metoda care sa 
//consume combustibilul, consum mediu optional
//vectorul de alimenatare 5l, 10l 3l, cat am pus
#include <iostream>
using namespace std;

class Masina {
public:
	double caprez;
	double capcurenta;
	int nralimentari;
	double* alimentari;
	int km;

	Masina(double _caprez, double _capcurenta, int _nralimentari, double* _alimentari, int _km)
	{
		this->caprez = _caprez;
		this->capcurenta = _capcurenta;
		this->nralimentari = _nralimentari;
		this->alimentari = _alimentari;
		this->km = _km;
	}
	
	void alimentare(double _litri)
	{
		if (capcurenta + _litri > caprez)
		{
			cout << "Nu pot intra atatia litri in masina\n";
		}
		else
		{
			cout << "\nS-a alimentat cu " << _litri << " litri\n";
			double* alimentarinoi = new double[nralimentari + 1];
			for (int i = 0; i < this->nralimentari; i++)
				alimentarinoi[i] = alimentari[i];
			alimentarinoi[nralimentari] = _litri;
			delete[] this->alimentari;
			this->alimentari = alimentarinoi;
			this->nralimentari = this->nralimentari + 1;
			this->capcurenta = this->capcurenta + _litri;
		}

	}
	double consumCombustibil(double _litri) {
		if (_litri > this->capcurenta) {
			cout << "\nNu se poate consuma mai mult decat capacitatea curenta\n";
			this->capcurenta = 0;
			return 0;
		}
		else
		{
			cout << "\nS-au consumat " << _litri << " litri\n";
			this->capcurenta = this->capcurenta - _litri;
			return this->capcurenta;
		}
	}

	void afisare()
	{
		cout << "Capacitate rezervor: " << this->caprez;
		cout << "\nCapacitate curenta: " << this->capcurenta;
		cout << "\nNr alimentari: " << this->nralimentari;
		cout << "\nAlimentari: ";
		for (int i = 0; i < this->nralimentari; i++)
			cout << this->alimentari[i] << " ";
		cout << "\n\n";
	}

	double consumMediu()
	{
		double sumaalim = 0;
		for (int i = 0; i < this->nralimentari; i++)
			sumaalim += alimentari[i];
		double litriconsumati = sumaalim - this->capcurenta;
		return (litriconsumati * 100) / km;
	}
};

int main() {
	Masina m1(60, 0, 0, 0, 56);
	m1.afisare();

	m1.alimentare(20);
	m1.afisare();

	m1.consumCombustibil(10);
	m1.afisare();

	cout << "\nConsumul mediu: " << m1.consumMediu();
	cout << "\n";

	return 0;
}