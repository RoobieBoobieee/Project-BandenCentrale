#include "Velg.h"

//constructor en deconstructor
Velg::Velg()
{
}
Velg::Velg(char n[], char f[], double p, int d, char t[], int a, int b, char k[], bool al)
	:Artikel(n, f, p, d, t, a)
{
	std::cout << "Constructed Velg()" << endl;
	
	this->setBreedte(b);
	this->setKleur(k);
	this->setAluminium(al);
}

Velg::~Velg()
{
}


//getters
int Velg::getBreedte() 
{
	return this->Breedte;
}

char* Velg::getKleur() 
{
	return this->Kleur;
}

bool Velg::getAluminium() 
{
	return this->Aluminium;
}


//setters
void Velg::setBreedte(int i)
{
	if (i < 0)
	{
		this->Breedte = 0;
	}
	else
	{
		this->Breedte = i;
	}
}

void Velg::setKleur(char s[])
{
	strcpy_s(this->Kleur, s);
}

void Velg::setAluminium(int i)
{
	if (i == 1)
	{
		this->Aluminium = true;
	}
	else
	{
		this->Aluminium = false;
	}
}


//print
void Velg::print()
{
	Artikel::print();

	cout << std::setw(20) << "Breedte (mm): ";
	cout << std::setw(20) << this->getBreedte();
	cout << "| " << std::setw(18) << "Kleur: ";
	cout << std::setw(20) << this->getKleur() << endl;
	cout << std::setw(20) << "Aluminium: ";
	cout << std::setw(20) << this->getAluminium() << endl;
	cout << "##############################################################################" << endl;
}
