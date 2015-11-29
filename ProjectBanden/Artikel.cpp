#include "Artikel.h"

//comstructor & deconstructor
Artikel::Artikel()
{
}

Artikel::~Artikel()
{
}

//getters
string Artikel::getNaam() const
{
	return Naam;
}

string Artikel::getFabrikant() const
{
	return Fabrikant;
}

double Artikel::getPrijs() const
{
	return Prijs;
}

int Artikel::getDiameter() const
{
	return Diameter;
}

string Artikel::getType() const
{
	return Type;
}

int Artikel::getAantal() const
{
	return Aantal;
}


//setters
void Artikel::setNaam(string s)
{
	Naam = s;
}

void Artikel::setFabrikant(string s)
{
	Fabrikant = s;
}

void Artikel::setPrijs(double d)
{
	Prijs = d;
}

void Artikel::setDiameter(int i)
{
	Diameter = i;
}

void Artikel::setType(string s)
{
	Type = s;
}

void Artikel::setAantal(int i)
{
	Aantal = i;
}