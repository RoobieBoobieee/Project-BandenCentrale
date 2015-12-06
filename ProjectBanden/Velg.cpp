#include "Velg.h"

//constructor en deconstructor
Velg::Velg()
{
}

Velg::~Velg()
{
}


//getters
int Velg::getBreedte() const
{
	return this->Breedte;
}

string Velg::getKleur() const
{
	return this->Kleur;
}

bool Velg::getAluminium() const
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

void Velg::setKleur(string s)
{
	this->Kleur = s;
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
void Velg::print() const
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
