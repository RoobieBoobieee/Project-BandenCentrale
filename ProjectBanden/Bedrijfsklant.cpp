#include "Bedrijfsklant.h"

Bedrijfsklant::Bedrijfsklant()
{
}

Bedrijfsklant::~Bedrijfsklant()
{
}


//getters
string Bedrijfsklant::getBTWnummer() const
{
	return this->BTWnummer;
}

double Bedrijfsklant::getVolumekorting() const
{
	return this->Volumekorting;
}

double Bedrijfsklant::getBedrijfskorting() const
{
	return this->Bedrijfskorting;
}


//setters
void Bedrijfsklant::setBTWnummer(string s)
{
	this->BTWnummer = s;
}

void Bedrijfsklant::setVolumekorting(int i) // kortingen worden rationaal opgeslagen voor later makkelijker met te rekenen
{
	if (i < 0 || i > 100)
	{
		this->Volumekorting = 0;
	}
	else
	{
		this->Volumekorting = (i/100);
	}
}

void Bedrijfsklant::setBedrijfskorting(int i)
{
	if (i < 0 || i > 100)
	{
		this->Bedrijfskorting = 0;
	}
	else
	{
		this->Bedrijfskorting = (i / 100);
	}
}


//print
void Bedrijfsklant::print() const
{
	Klant::print();

	cout << std::setw(20) << "BTW Nummer: ";
	cout << std::setw(60) << this->getBTWnummer() << endl;

	cout << std::setw(20) << "Volume Korting: ";
	cout << std::setw(20) << this->getKorting();
	cout << "| " << std::setw(18) << "Bedrijfs Korting: ";
	cout << std::setw(20) << this->getKorting2() << endl;
}
