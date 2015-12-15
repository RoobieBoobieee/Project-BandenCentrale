#include "Bedrijfsklant.h"

Bedrijfsklant::Bedrijfsklant()
{
}
Bedrijfsklant::Bedrijfsklant(char n[], char a[], double k, char b[], double k2, char btw[], double v, double bk)
{
	std::cout << "Constructed BedrijfsKlant()";
	this->setNaam(n);
	this->setAdres(a);
	this->setKorting(k);
	this->setKorting2(k2);
	this->setBedrijf(b);

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

double Bedrijfsklant::getVolumekorting() 
{
	return this->Volumekorting;
}

double Bedrijfsklant::getBedrijfskorting() 
{
	return this->Bedrijfskorting;
}


//setters
void Bedrijfsklant::setBTWnummer(char s[])
{
	strcpy_s(this->BTWnummer, s);
}

void Bedrijfsklant::setVolumekorting(double d) // kortingen worden rationaal opgeslagen voor later makkelijker met te rekenen
{
		this->Volumekorting = d;
}

void Bedrijfsklant::setBedrijfskorting(double d)
{
		this->Bedrijfskorting = d;
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
