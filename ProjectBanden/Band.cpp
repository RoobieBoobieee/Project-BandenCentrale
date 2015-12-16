#include "Band.h"


//constructor en deconstructor
Band::Band()
{
}

Band::Band(char n[], char f[], double p, int d, char t[], int a, int b, int h, char s[], bool se)
	:Artikel(n, f, p, d,t, a)
{
	std::cout << "Constructed Band()" << endl;

	this->setBreedte(b);
	this->setHoogte(h);
	this->setSnelheidsindex(s);
	this->setSeizoen(se);
}

Band::~Band()
{
}


//getters
int Band::getBreedte() 
{
	return this->Breedte;
}

int Band::getHoogte() 
{
	return this->Hoogte;
}

 char* Band::getSnelheidsindex() 
{
	return this->Snelheidsindex;
}

 char* Band::getSeizoen() 
{
	return this->Seizoen;
}

int Band::getSeizoenint() 
{
	if (strcmp(this->Seizoen, "Winter") == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

void Band::setSnelheidsindex(char s[])
{
	strcpy_s(this->Snelheidsindex, s);
}

void Band::setSeizoen(int i)
{
	if (i == 1)
	{
		strcpy_s(this->Seizoen, "Winter");
	}
	else
	{
		strcpy_s(this->Seizoen, "Zomer");
	}
}


//print
void Band::print()
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