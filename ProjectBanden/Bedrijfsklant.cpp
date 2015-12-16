#include "Bedrijfsklant.h"

Bedrijfsklant::Bedrijfsklant()
{
}
Bedrijfsklant::Bedrijfsklant(char n[], char a[], int k, char b[], int k2, char btw[], int v, int bk)
	:Klant(n, a, k, b, k2)
{
	std::cout << "Constructed BedrijfsKlant()";

	this->setBTWnummer(btw);
	this->setVolumekorting(v);
	this->setBedrijfskorting(bk);
}


Bedrijfsklant::~Bedrijfsklant()
{
}


//getters
 char * Bedrijfsklant::getBTWnummer() 
{
	return this->BTWnummer;
}

 int Bedrijfsklant::getVolumekorting()
{
	return this->Volumekorting;
}

 int Bedrijfsklant::getBedrijfskorting()
{
	return this->Bedrijfskorting;
}


//setters
void Bedrijfsklant::setBTWnummer(char s[])
{
	strcpy_s(this->BTWnummer, s);
}

void Bedrijfsklant::setVolumekorting(int i) 
{
		this->Volumekorting = i;
}

void Bedrijfsklant::setBedrijfskorting(int i)
{
		this->Bedrijfskorting = i;
}


//print
void Bedrijfsklant::print()
{
	Klant::print();

	cout << std::setw(20) << "BTW Nummer: ";
	cout << std::setw(20) << this->getBTWnummer();
	cout << "| " << std::setw(18) << "Bedrijf";
	cout << std::setw(20) << this->getBedrijf() << endl;

	cout << std::setw(20) << "Volume Korting: ";
	cout << std::setw(20) << this->getKorting();
	cout << "| " << std::setw(18) << "Bedrijfs Korting: ";
	cout << std::setw(20) << this->getKorting2() << endl;

}
