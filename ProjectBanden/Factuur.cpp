#include "Factuur.h"

Factuur::Factuur()
{

}


Factuur::~Factuur()
{
}

//getters

int Factuur::getFactuurnummer() const
{
	return Factuurnummer;
}

Klant const * Factuur::getKlant() const
{
	return _Klant;
}

vector<Artikel*> const * Factuur::getArtikels() const
{
	return nullptr;
}

double Factuur::getTotaalprijs() const
{
	return Totaalprijs;
}

double Factuur::getKorting() const
{
	return Korting;
}


//setters

void Factuur::setFactuurnummer(int i)
{
}

void Factuur::setKlant(Klant * k)
{
	_Klant = k;
}

void Factuur::setArtikels(vector<Artikel*>)
{
}

void Factuur::setTotaalprijs(double d)
{
	Totaalprijs = d;
}

void Factuur::setKorting(int i)
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

void Factuur::addArtikel(Artikel * a)
{
	addTotaalprijs(a->getPrijs());
	Artikels.push_back(a);
}


//private setters 

void Factuur::addTotaalprijs(double d)
{
	Totaalprijs += d;
}
