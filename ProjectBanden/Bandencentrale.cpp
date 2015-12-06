#include "Bandencentrale.h"

//constructor en deconstructor
Bandencentrale::Bandencentrale()
{
}

Bandencentrale::~Bandencentrale()
{
}


//getters
string Bandencentrale::getNaam() const 
{
	return this->Naam;
}

string Bandencentrale::getAdres() const
{
	return this->Adres;
}

vector<Klant*> const* Bandencentrale::getKlanten() const
{
	return &Klanten;
}

vector<Artikel*> const* Bandencentrale::getArtikels() const
{
	return &Artikels;
}


//setters
void Bandencentrale::setNaam(std::string s)
{
	this->Naam = s;
}

void Bandencentrale::setAdres(string s)
{
	this->Adres = s;
}

void Bandencentrale::setKlanten(vector<Klant*> v)
{
	this->Klanten = v;
}

void Bandencentrale::setArtikels(vector<Artikel*> v)
{
	this->Artikels = v;
}


//add
void Bandencentrale::addArtikel(Artikel* a)
{
	if (a == NULL) {
		int choice = 0;

		do
		{
			cout << "Wilt u een band (1) of een velg (2) toevoegen? (3 om te stoppen)" << endl;
			cout << "> ";
			cin >> choice;
			cin.get();
			switch (choice)
			{
			case 1:
				Artikels.push_back(setupBand());
				break;

			case 2:
				Artikels.push_back(setupVelg());
				break;

			case 3:
				break;

			default:
				cout << "Ongeldige keuze ..." << endl;
				break;
			}

		} while (choice < 1 && choice > 3);

	}
	else
	{
		Artikels.push_back(a);
	}
}

void Bandencentrale::addClient(Klant * k)
{
	if (k == NULL) {
		int choice = 0;

		do
		{
			cout << "Wilt u een gewone (1) of een bedrijfs (2) klant toevoegen? (3 om te stoppen)" << endl;
			cout << "> ";
			cin >> choice;
			cin.get();
			switch (choice)
			{
			case 1:
				Klanten.push_back(setupKlant());
				break;

			case 2:
				Klanten.push_back(setupBedrijfsklant());
				break;

			case 3:
				break;

			default:
				cout << "Ongeldige keuze ..." << endl;
				break;
			}

		} while (choice < 1 && choice > 3);

	}
	Klanten.push_back(k);
}

//setup
void Bandencentrale::setupArtikel(Artikel * a)
{
	string str;
	double dbl;
	int intgr;

	cout << "Naam: ";
	getline(std::cin, str);
	a->setNaam(str);

	cout << "Fabrikant: ";
	getline(std::cin, str);
	a->setFabrikant(str);

	cout << "Prijs: ";
	cin >> dbl;
	cin.get();
	a->setPrijs(dbl);

	cout << "Diameter: ";
	cin >> intgr;
	cin.get();
	a->setDiameter(intgr);

	cout << "Aantal: ";
	cin >> intgr;
	cin.get();
	a->setAantal(intgr);

}

Artikel * Bandencentrale::setupBand()
{
	Artikel * a = new Band;
	a->setType("Band");
	setupArtikel(a);

	Band *b = dynamic_cast<Band *>(a);

	string str;
	int intgr;

	cout << "Breedte: ";
	cin >> intgr;
	cin.get();
	b->setBreedte(intgr);

	cout << "Hoogte: ";
	cin >> intgr;
	cin.get();
	b->setHoogte(intgr);

	cout << "Snelheidsindex: ";
	getline(std::cin, str);
	b->setSnelheidsindex(str);

	cout << "Seizoen (Zomer=0; Winter = 1): ";
	cin >> intgr;
	cin.get();
	b->setSeizoen(intgr);
	
	return(b);
}

Artikel * Bandencentrale::setupVelg()
{
	Artikel * a = new Velg;
	a->setType("Velg");
	setupArtikel(a);

	Velg *b = dynamic_cast<Velg *>(a);

	string str;
	int intgr;

	cout << "Breedte: ";
	cin >> intgr;
	cin.get();
	b->setBreedte(intgr);

	cout << "Kleur: ";
	getline(std::cin, str);
	b->setKleur(str);

	cout << "Aluminium: (Nee=0; Ja=1)" << endl;
	cin >> intgr;
	cin.get();
	b->setAluminium(intgr);

	return(b);
}

Klant * Bandencentrale::setupKlant(Klant * k)
{
	string str;
	int intgr;

	cout << "Naam: ";
	getline(std::cin, str);
	k->setNaam(str);

	cout << "Adres: ";
	getline(std::cin, str);
	k->setAdres(str);

	cout << "Korting: ";
	cin >> intgr;
	cin.get();
	k->setKorting(intgr);

	cout << "Bedrijf (leeg voor geen): ";
	getline(std::cin, str);
	k->setBedrijf(str);

	cout << "Korting 2: ";
	cin >> intgr;
	cin.get();
	k->setKorting2(intgr);

	return (k);
}

Klant * Bandencentrale::setupBedrijfsklant()
{
		Klant * k = new Bedrijfsklant;

		this->setupKlant(k);

		Bedrijfsklant *bedrijfsklant = dynamic_cast<Bedrijfsklant *>(k);

		string str;
		int intgr;

		cout << "BTW Nummer: ";
		getline(std::cin, str);
		bedrijfsklant->setBTWnummer(str);

		cout << "Volumekorting: ";
		cin >> intgr;
		cin.get();
		bedrijfsklant->setVolumekorting(intgr);

		cout << "Bedrijfskorting: ";
		cin >> intgr;
		cin.get();
		bedrijfsklant->setBedrijfskorting(intgr);

		return (dynamic_cast<Klant *>(bedrijfsklant));
}


//print
void Bandencentrale::printClients() const
{
	system("cls");

	for (vector<Klant*>::const_iterator i = this->getKlanten()->cbegin(); i != this->getKlanten()->cend(); ++i)
	{
		
		if ((*i)->getBedrijf().compare("") == 0) {
			(*i)->print();
		} 
		else
		{
			const Bedrijfsklant *bedrijfsklant = dynamic_cast<const Bedrijfsklant *>(*i);
			bedrijfsklant->print();
		}
	}

	if (this->getKlanten()->size() == 0)
	{
		cout << "Er zijn geen klanten." << endl;
	}
	system("pause");
}

void Bandencentrale::printArticles(string s) const
{
	system("cls");

	for (vector<Artikel*>::const_iterator i = this->getArtikels()->cbegin(); i != this->getArtikels()->cend(); ++i)
	{

		if ((*i)->getType().compare(s) == 0 || s.compare("All") == 0) {

			if ((*i)->getType().compare("Band") == 0)
			{
				const Band *band = dynamic_cast<const Band *>(*i);

				band->print();
			}
			else if ((*i)->getType().compare("Velg") == 0)
			{
				const Velg *velg = dynamic_cast<const Velg *>(*i);

				velg->print();
			}
		}
	}

	if (this->getArtikels()->size() == 0)
	{
		cout << "Er zijn geen artikels." << endl;
	}
	system("pause");
}

void Bandencentrale::printSizes() const
{
	system("cls");

	for (vector<Artikel*>::const_iterator i = this->getArtikels()->cbegin(); i != this->getArtikels()->cend(); ++i)
	{
		cout << (*i)->getDiameter() << " mm" << endl;
	}

	if (this->getArtikels()->size() == 0)
	{
		cout << "Er zijn geen artikels." << endl;
	}

	system("pause");
}


//search

int Bandencentrale::searchArticles(string s)
{
	int index = 0;
	for (vector<Artikel*>::const_iterator i = this->getArtikels()->cbegin(); i != this->getArtikels()->cend(); ++i)
	{
		if ((*i)->getNaam().compare(s) == 0)
		{
			return (index);
		}
		index++;
	}

	return -1;
}

int Bandencentrale::searchClients(string s)
{
	int index = 0;
	for (vector<Klant*>::const_iterator i = this->getKlanten()->cbegin(); i != this->getKlanten()->cend(); ++i)
	{
		if ((*i)->getNaam().compare(s) == 0)
		{
			return (index);
		}
		index++;
	}

	return -1;
}

void Bandencentrale::removeArticle()
{
	string str;
	int index = 0;
	do
	{
		cout << "Naam van artikel dat u wilt verwijderen: ";
		getline(std::cin, str);

		index = searchArticles(str);

		if (index >= 0)
		{
			delete * (Artikels.begin() + index);
			Artikels.erase(Artikels.begin() + index);
			cout << "Artikel verwijderd!" << endl;
			system("pause");
		}
		else
		{
			cout << "Geen artikel gevonden. Wilt u opnieuw proberen? (j/n)";
			getline(std::cin, str);
		}
	} while (str.compare("j") && index < 0);

}

void Bandencentrale::removeClient()
{
	string str;
	int index = 0;
	do
	{
		cout << "Naam van de klant die u wilt verwijderen: ";
		getline(std::cin, str);

		index = searchClients(str);

		if (index >= 0)
		{
			delete * (Klanten.begin() + index);
			Klanten.erase(Klanten.begin() + index);
			cout << "Klant verwijderd!" << endl;
			system("pause");
		}
		else
		{
			cout << "Geen klant gevonden. Wilt u opnieuw proberen? (j/n)";
			getline(std::cin, str);
		}
	} while (str.compare("j") && index < 0);

}


