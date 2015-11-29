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
