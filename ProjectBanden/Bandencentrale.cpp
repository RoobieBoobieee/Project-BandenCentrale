#include "Bandencentrale.h"



//constructor en deconstructor
Bandencentrale::Bandencentrale()
{
}

Bandencentrale::~Bandencentrale()
{
}


//getters
string Bandencentrale::getNaam() const 
{
	return Bandencentrale::naam;
}

string Bandencentrale::getAdres() const
{
	return string();
}

vector<Klant*> const* Bandencentrale::getKlanten() const
{
	return &Klanten;
}


vector<Artikel*> const* Bandencentrale::getArtikels() const
{
	return &Artikels;
}


//setters
void Bandencentrale::setNaam(std::string n)
{
	Bandencentrale::naam = n;
}

void Bandencentrale::setAdres(string)
{
}

void Bandencentrale::setKlanten(vector<Klant*> v)
{
}

void Bandencentrale::setArtikels(vector<Artikel*> v)
{
}

void Bandencentrale::addArtikel(Artikel* a)
{
	Artikels.push_back(a);
}


