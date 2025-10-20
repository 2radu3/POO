#include <iostream>
using namespace std;



int main()
{
	int* p1; //p1 este un pointer de tipul int, deci va contine zona de memorie la care este memorat un nr intreg
	char* s; // --||-- contine zona de memorie unde este memorat un caracter
	int i = 10;
	p1 = &i;
	cout << *p1;

	return 0;
}