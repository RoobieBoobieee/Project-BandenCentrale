#include "Factuur.h"

Factuur::Factuur()
{

}

Factuur::~Factuur()
{
}


//getters
int Factuur::getFactuurnummer() 
{
	return this->Factuurnummer;
}

Klant * Factuur::getKlant() 
{
	return this->_Klant;
}

vector <Artikel*> * Factuur::getArtikels() 
{
	return &Artikels;
}

double Factuur::getTotaalprijs() 
{
	return this->Totaalprijs;
}

int Factuur::getKorting()
{
	return this->Korting;
}


//setters
void Factuur::setFactuurnummer(int i)
{
	this->Factuurnummer = i;
}

void Factuur::setKlant(Klant * k)
{
	this->_Klant = k;
}

void Factuur::setArtikels(vector<Artikel*> v)
{
	this->Artikels = v;
}

void Factuur::setTotaalprijs(double d)
{
	this->Totaalprijs = d;
}

void Factuur::setKorting(int i)
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


//add
void Factuur::addArtikel(Artikel * a)
{
	this->addTotaalprijs(a->getPrijs());
	this->Artikels.push_back(a);
}

void Factuur::print()
{
	cout << std::setw(20) << "Factuur #: ";
	cout << std::setw(20) << this->getFactuurnummer() << endl;
	cout << std::setw(20) << "Klant: " << endl;

	this->getKlant()->print();

	cout << std::setw(20) << "Artikels: " << endl;

	for (vector<Artikel*>::iterator i = this->getArtikels()->begin(); i != this->getArtikels()->end(); ++i)
	{
		if (strcmp((*i)->getType(), "Band") == 0)
		{
			Band *band = dynamic_cast<Band *>(*i);
			band->print();
		}
		else if (strcmp((*i)->getType(), "Velg") == 0)
		{
			Velg *velg = dynamic_cast<Velg *>(*i);
			velg->print();
		}
	}

	cout << endl;
	cout << std::setw(20) << "Totaal Prijs: ";
	cout << std::setw(20) << this->getTotaalprijs();
	cout << std::setw(20) << "Korting: ";
	cout << std::setw(20) << this->getKorting() << endl;
	cout << "##############################################################################" << endl;
}


//private setters 
void Factuur::addTotaalprijs(double d)
{
	this->Totaalprijs += d;
}
