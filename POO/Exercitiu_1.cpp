#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

void PrimulEx()
{
	int* p1; // p1 este un pointer de tipul int, deci va contine zona de memorie la care este memorat un nr intreg
	char* s; // --||-- contine zona de memorie unde este memorat un caracter
	int i = 10;
	char j;
	p1 = &i;
	s = &j;
	cout << *p1 << endl;
	cout << p1 << endl;
	p1++;
	cout << p1 << endl; // s-au adunat la adresa lui p1 4 octeti, adica sizeof(int);
	cout << sizeof(*p1) << endl;

	cout << "Pentru s:" << endl;
	cout << s << endl;
	s--;
	cout << s << endl;

}

void Ex2()
{
	char s[100];
	int lungime;
	//for (lungime=0;s[lungime];lungime++)
	//putem parcurge sirul si folosind un pointer

	char* p;
	for (p = s; *p; p++);
		lungime = p - s;
		cout << lungime << endl;
	//unsigned strlen(const char* s);
	cout << strlen(s) << endl;
	int v[100];
	v[0] = 2;
	v[2] = 3;
	int i = 2;
	cout << *(v + i) << endl;

	int m[10][10];
	m[0][0] = 1;
	cout << m[0] << endl;
	cout << *m << endl;
	//cout << m[0] << endl;

}

void Ex3()
{
	char sursa[3]="DA", destinatie[3]="NU";
	//cout << destinatie << endl;
	//strcpy(destinatie, sursa);
	//cout << destinatie << endl;

	//Folositi pointeri pentru parcurgerea sirurilor

	char* p1;
	for (p1 = sursa; *p1; p1++)
		destinatie[*p1] = sursa[*p1];
	destinatie[*p1] == NULL;
	cout << destinatie << endl;
	
}

int main()
{
	Ex3();

	return 0;
}