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
	return this->Factuurnummer;
}

Klant const * Factuur::getKlant() const
{
	return this->_Klant;
}

vector <Artikel*> const * Factuur::getArtikels() const
{
	return &Artikels;
}

double Factuur::getTotaalprijs() const
{
	return this->Totaalprijs;
}

double Factuur::getKorting() const
{
	return this->Korting;
}


//setters
void Factuur::setFactuurnummer(int i)
{
	this->Factuurnummer = i;
}

void Factuur::setKlant(Klant * k)
{
	this->_Klant = k;
}

void Factuur::setArtikels(vector<Artikel*> v)
{
	this->Artikels = v;
}

void Factuur::setTotaalprijs(double d)
{
	this->Totaalprijs = d;
}

void Factuur::setKorting(int i)
{
	if (i < 0 || i > 100)
	{
		this->Korting = 0;
	}
	else
	{
		this->Korting = (i / 100);
	}
}


//add
void Factuur::addArtikel(Artikel * a)
{
	this->addTotaalprijs(a->getPrijs());
	this->Artikels.push_back(a);
}


//private setters 
void Factuur::addTotaalprijs(double d)
{
	this->Totaalprijs += d;
}
