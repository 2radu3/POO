#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Prieteni
{
public:
	int varsta;
	char* nume;
	char* prenume;

	void setNumePrenume(const char* nume_nou, const char* prenume_nou)
	{
		nume = new char[strlen(nume_nou) + 1];
		prenume = new char[strlen(prenume_nou) + 1];
		strcpy(nume, nume_nou);
		strcpy(prenume, prenume_nou);
	}

	bool verificarePrenume(const char* prenumeImpartire)
	{
		char prenume_impartit[100];
		strcpy(prenume_impartit, prenumeImpartire);

		char* numeSfant = strtok(prenume_impartit, " ");
		while (numeSfant != nullptr)
		{
			if (strcmp(numeSfant, "Mihai") == 0)
			{
				return true;
			}
			numeSfant = strtok(nullptr, " ");
		}
		return false;
	}
};

int main()
{
	Prieteni p[] = {
		Prieteni(),
		Prieteni(),
		Prieteni()
	};

	const int n = sizeof(p) / sizeof(p[0]);
	int cadouri = 0;

	p[0].setNumePrenume("Eusebiu", "Mihai Ion");
	p[1].setNumePrenume("Horatiu", "John Ion");
	p[2].setNumePrenume("Marcus", "Mihai");

	for (int i = 0; i < n; i++)
	{
		if (p[i].verificarePrenume(p[i].prenume))
		{
			cadouri++;
		}
	}

	cout << cadouri;

	for (int i = 0; i < n; i++)
	{
		delete[] p[i].nume;
		delete[] p[i].prenume;

	}
	return 0;
}