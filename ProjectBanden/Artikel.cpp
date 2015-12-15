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
 char* Artikel::getNaam() 
{
	return this->Naam;
}

 char* Artikel::getFabrikant() 
{
	return this->Fabrikant;
}

double Artikel::getPrijs() 
{
	return this->Prijs;
}

int Artikel::getDiameter() 
{
	return this->Diameter;
}

char* Artikel::getType() 
{
	return this->Type;
}

int Artikel::getAantal() 
{
	return this->Aantal;
}


//setters
void Artikel::setNaam(char s[])
{
	strcpy_s(this->Naam, s);
}

void Artikel::setFabrikant(char s[])
{
	strcpy_s(this->Fabrikant, s);
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

void Artikel::setType(char s[])
{
	// Just to be sure. Gebruiker kan hier normaal niets verkeerd doen aangezien programma deze prop altijd invult. 
	if (strcmp(s, "Velg") == 0)
	{
		strcpy_s(this->Type, s);
	}
	else
	{
		strcpy_s(this->Type, "Band");
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


void Artikel::print()
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
