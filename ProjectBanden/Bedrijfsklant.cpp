#include "Bedrijfsklant.h"

Bedrijfsklant::Bedrijfsklant()
{
}


Bedrijfsklant::~Bedrijfsklant()
{
}

string Bedrijfsklant::getBTWnummer() const
{
	return BTWnummer;
}

double Bedrijfsklant::getVolumekorting() const
{
	return Volumekorting;
}

double Bedrijfsklant::getBedrijfskorting() const
{
	return Bedrijfskorting;
}

void Bedrijfsklant::setBTWnummer(string s)
{
	BTWnummer = s;
}

// kortingen worden rationaal opgeslagen voor later makkelijker met te rekenen
void Bedrijfsklant::setVolumekorting(int i)
{
	if (i < 0 || i > 100)
	{
		Volumekorting = 0;
	}
	else
	{
		Volumekorting = (i/100);
	}
}

void Bedrijfsklant::setBedrijfskorting(int i)
{
	if (i < 0 || i > 100)
	{
		Bedrijfskorting = 0;
	}
	else
	{
		Bedrijfskorting = (i / 100);
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
