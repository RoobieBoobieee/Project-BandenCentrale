#include "Klant.h"

Klant::Klant()
{
}

Klant::~Klant()
{
}


//getters
string Klant::getNaam() const
{
	return this->Naam;
}

string Klant::getAdres() const
{
	return this->Adres;
}

double Klant::getKorting() const
{
	return this->Korting;
}

string Klant::getBedrijf() const
{
	return this->Bedrijf;
}

double Klant::getKorting2() const
{
	return this->Korting2;
}


//setters
void Klant::setNaam(string s)
{
	this->Naam = s;
}

void Klant::setAdres(string s)
{
	this->Adres = s;
}

void Klant::setKorting(int i)
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

void Klant::setBedrijf(string s)
{
	this->Bedrijf = s;
}

void Klant::setKorting2(int i)
{
	if (i < 0 || i > 100)
	{
		this->Korting2 = 0;
	}
	else
	{
		this->Korting2 = (i / 100);
	}
}


//print
void Klant::print() const
{
	cout << std::setw(20) << "Naam: ";
	cout << std::setw(20) << this->getNaam() << endl;

	cout << std::setw(20) << "Adres:";
	cout << std::setw(60) << this->getAdres() << endl;

	cout << std::setw(20) << "Korting: ";
	cout << std::setw(20) << this->getKorting();
	cout << "| " << std::setw(18) << "Korting2: ";
	cout << std::setw(20) << this->getKorting2() << endl;
}
