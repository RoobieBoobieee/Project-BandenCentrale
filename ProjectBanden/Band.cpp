#include "Band.h"

//constructor en deconstructor
Band::Band()
{
}

Band::~Band()
{
}


//getters
int Band::getBreedte() const
{
	return this->Breedte;
}

int Band::getHoogte() const
{
	return this->Hoogte;
}

string Band::getSnelheidsindex() const
{
	return this->Snelheidsindex;
}

string Band::getSeizoen() const
{
	return this->Seizoen;
}


//setters
void Band::setBreedte(int i)
{
	if (i < 0)
	{
		this->Breedte = 0;
	}
	else
	{
		this->Breedte = i;
	}
}

void Band::setHoogte(int i)
{
	if (i < 0)
	{
		this->Hoogte = 0;
	}
	else
	{
		this->Hoogte = i;
	}
}

void Band::setSnelheidsindex(string s)
{
	this->Snelheidsindex = s;
}

void Band::setSeizoen(int i)
{
	if (i == 1)
	{
		this->Seizoen = "Winter";
	}
	else
	{
		this->Seizoen = "Zomer";
	}
}


//print
void Band::print() const
{
	Artikel::print();

	cout << std::setw(20) << "Breedte (mm): ";
	cout << std::setw(20) << this->getBreedte();
	cout << "| " << std::setw(18) << "Hoogte (mm): ";
	cout << std::setw(20) << this->getHoogte() << endl;
	cout << std::setw(20) << "Snelheidsindex: ";
	cout << std::setw(20) << this->getSnelheidsindex();
	cout << "| " << std::setw(18) << "Seizoen: ";
	cout << std::setw(20) << this->getSeizoen() << endl;
	cout << "##############################################################################" << endl;
}