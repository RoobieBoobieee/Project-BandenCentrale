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
	return Bandencentrale::naam;
}

string Bandencentrale::getAdres() const
{
	return string();
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
void Bandencentrale::setNaam(std::string n)
{
	Bandencentrale::naam = n;
}

void Bandencentrale::setAdres(string)
{
}

void Bandencentrale::setKlanten(vector<Klant*> v)
{
}

void Bandencentrale::setArtikels(vector<Artikel*> v)
{
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
		k = setupKlant();
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
	b->setBreedte(intgr);

	cout << "Kleur: ";
	getline(std::cin, str);
	b->setKleur(str);

	cout << "Aluminium: (Nee=0; Ja=1)" << endl;
	cin >> intgr;
	b->setAluminium(intgr);

	return(b);
}

Klant * Bandencentrale::setupKlant()
{

	Bedrijfsklant * k = new Bedrijfsklant; //VRAGEN

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
			
	if (k->getBedrijf().compare(""))
	{
		Bedrijfsklant *bedrijfsklant = dynamic_cast<Bedrijfsklant *>(k);
						
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

		return bedrijfsklant;
	}

	return k;
}

//print
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


