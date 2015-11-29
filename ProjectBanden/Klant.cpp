#include "Klant.h"


Klant::Klant()
{
}


Klant::~Klant()
{
}

string Klant::getNaam() const
{
	return Naam;
}

string Klant::getAdres() const
{
	return Adres;
}

double Klant::getKorting() const
{
	return Korting;
}

string Klant::getBedrijf() const
{
	return Bedrijf;
}

double Klant::getKorting2() const
{
	return Korting2;
}

void Klant::setNaam(string s)
{
	Naam = s;
}

void Klant::setAdres(string s)
{
	Adres = s;
}

void Klant::setKorting(int i)
{
	if (i < 0 || i > 100)
	{
		Korting = 0;
	}
	else
	{
		Korting = (i / 100);
	}
}

void Klant::setBedrijf(string s)
{
	Bedrijf = s;
}

void Klant::setKorting2(int i)
{
	if (i < 0 || i > 100)
	{
		Korting2 = 0;
	}
	else
	{
		Korting2 = (i / 100);
	}
}
