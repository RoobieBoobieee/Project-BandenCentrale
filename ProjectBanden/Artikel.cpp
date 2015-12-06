#include "Artikel.h"

#include "Band.h"
#include "Velg.h"

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
	return this->Naam;
}

string Artikel::getFabrikant() const
{
	return this->Fabrikant;
}

double Artikel::getPrijs() const
{
	return this->Prijs;
}

int Artikel::getDiameter() const
{
	return this->Diameter;
}

string Artikel::getType() const
{
	return this->Type;
}

int Artikel::getAantal() const
{
	return this->Aantal;
}


//setters
void Artikel::setNaam(string s)
{
	this->Naam = s;
}

void Artikel::setFabrikant(string s)
{
	this->Fabrikant = s;
}

void Artikel::setPrijs(double d)
{
	if (d < 0) 
	{
		this->Prijs = 0;
	}
	else 
	{
		this->Prijs = d;
	}
}

void Artikel::setDiameter(int i)
{
	if (i < 0)
	{
		this->Diameter = 0;
	}
	else
	{
		this->Diameter = i;
	}
}

void Artikel::setType(string s)
{
	// Just to be sure. Gebruiker kan hier normaal niets verkeerd doen aangezien programma deze prop altijd invult. 
	if (s.compare("Velg") == 0)
	{
		this->Type = s;
	}
	else
	{
		this->Type = "Band";
	}
}

void Artikel::setAantal(int i)
{
	if (i < 0)
	{
		this->Aantal = 0;
	}
	else
	{
		this->Aantal = i;
	}
}


void Artikel::print() const
{
	cout << std::setw(20) << "Naam: ";
	cout << std::setw(20) << this->getNaam();
	cout << "| " << std::setw(18) << "Fabrikant: ";
	cout << std::setw(20) << this->getFabrikant() << endl;

	cout << std::setw(20) << "Prijs (Euro): ";
	cout << std::setw(20) << this->getPrijs();
	cout << "| " << std::setw(18) << "Diameter (mm): ";
	cout << std::setw(20) << this->getDiameter() << endl;

	cout << std::setw(20) << "Type: ";
	cout << std::setw(20) << this->getType();
	cout << "| " << std::setw(18) << "Aantal: ";
	cout << std::setw(20) << this->getAantal() << endl;
}
