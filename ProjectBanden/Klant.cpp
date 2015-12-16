#include "Klant.h"

#include "StringSerializer.cpp"

//constructor en deconstructor
Klant::Klant()
{
}

Klant::Klant(char n[], char a[], int k, char b[], int k2)
{
	std::cout << "Constructed BedrijfsKlant()";
	this->setNaam(n);
	this->setAdres(a);
	this->setKorting(k);
	this->setKorting2(k2);
	this->setBedrijf(b);
}

Klant::~Klant()
{
}


//getters
 char* Klant::getNaam() 
{
	return this->Naam;
}

 char* Klant::getAdres() 
{
	return this->Adres;
}

 int Klant::getKorting()
{
	return this->Korting;
}

 char* Klant::getBedrijf() 
{
	return this->Bedrijf;
}

 int Klant::getKorting2()
{
	return this->Korting2;
}


//setters
void Klant::setNaam(char s[])
{
	strcpy_s(this->Naam ,s);
}

void Klant::setAdres(char s[])
{
	strcpy_s(this->Adres, s);
}

void Klant::setKorting(int d)
{
	this->Korting = d;
}

void Klant::setBedrijf(char s[])
{
	strcpy_s(this->Bedrijf, s);
}

void Klant::setKorting2(int d)
{
	this->Korting2 = d;
}


//print
void Klant::print()
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