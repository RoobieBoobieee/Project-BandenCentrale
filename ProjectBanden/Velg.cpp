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
	return Breedte;
}

string Velg::getKleur() const
{
	return Kleur;
}

bool Velg::getAluminium() const
{
	return Aluminium;
}

//setters
void Velg::setBreedte(int i)
{
	if (i < 0)
	{
		Breedte = 0;
	}
	else
	{
		Breedte = i;
	}
}

void Velg::setKleur(string s)
{
	Kleur = s;
}

void Velg::setAluminium(int i)
{
	if (i == 1)
	{
		Aluminium = true;
	}
	else
	{
		Aluminium = false;
	}
}
