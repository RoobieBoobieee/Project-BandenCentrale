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

		} while (choice < 1 || choice > 3);

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

		} while (choice < 1 || choice > 3);

	}
	else 
	{
		Klanten.push_back(k);
	}
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

	std::ofstream outCredit("data/banden.dat", ios::app | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	outCredit.write(reinterpret_cast< const char * >(b), sizeof(Band));
	
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

	std::ofstream outCredit("data/velgen.dat", ios::app | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} 

	outCredit.write(reinterpret_cast< const char * >(b), sizeof(Velg));

	return(b);
}

Klant * Bandencentrale::setupKlant()
{
	Klant* k = new Klant;

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

	cout << "Korting 2: ";
	cin >> intgr;
	cin.get();
	k->setKorting2(intgr);

	std::ofstream outCredit("data/klanten.dat", ios::app | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	outCredit.write(reinterpret_cast< const char * >(k), sizeof(Klant));

	return (k);
}

Klant * Bandencentrale::setupBedrijfsklant()
{
		Bedrijfsklant* k = new Bedrijfsklant;

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

		cout << "Korting 2: ";
		cin >> intgr;
		cin.get();
		k->setKorting2(intgr);

		cout << "Bedrijf: ";
		getline(std::cin, str);
		k->setBedrijf(str);

		cout << "BTW Nummer: ";
		getline(std::cin, str);
		k->setBTWnummer(str);

		cout << "Volumekorting: ";
		cin >> intgr;
		cin.get();
		k->setVolumekorting(intgr);

		cout << "Bedrijfskorting: ";
		cin >> intgr;
		cin.get();
		k->setBedrijfskorting(intgr);

		std::ofstream outCredit("data/bedrijfsklanten.dat", ios::app | ios::binary);

		if (!outCredit)
		{
			cerr << "File could not be opened." << endl;
			exit(1);
		}

		outCredit.write(reinterpret_cast< const char * >(k), sizeof(Bedrijfsklant));

		return(k);
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

		cout << "##############################################################################" << endl;
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


//remove 

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


// inlezen

void Bandencentrale::readData()
{
	//velgen

	std::ifstream inVelgen("data/velgen.dat", ios::binary);

	if (!inVelgen)
	{
		cerr << "File could not be opened. - velgen" << endl;
	}
	else {

		Velg * v = new Velg;

		inVelgen.read(reinterpret_cast<char *>(v), sizeof(Velg));

		while (inVelgen && !inVelgen.eof())
		{

			Velg * nv = new Velg;

			nv->setBreedte(v->getBreedte());
			nv->setKleur(v->getKleur());
			nv->setAluminium(v->getAluminium());

			Artikel *a = dynamic_cast<Artikel *>(v);

			nv->setNaam(a->getNaam());
			nv->setFabrikant(a->getFabrikant());
			nv->setPrijs(a->getPrijs());
			nv->setDiameter(a->getDiameter());
			nv->setType(a->getType());
			nv->setAantal(a->getAantal());

			this->addArtikel(nv);

			inVelgen.read(reinterpret_cast<char *>(v), sizeof(Velg));
		}
	}

	//banden

	std::ifstream inBanden("data/banden.dat", ios::binary);

	if (!inBanden)
	{
		cerr << "File could not be opened. - banden" << endl;
	}
	else {

		Band * b = new Band;

		inBanden.read(reinterpret_cast<char *>(b), sizeof(Band));

		while (inBanden && !inBanden.eof())
		{

			Band * nb = new Band;

			nb->setBreedte(b->getBreedte());
			nb->setHoogte(b->getHoogte());
			nb->setSnelheidsindex(b->getSnelheidsindex());
			nb->setSeizoen(b->getSeizoenint());

			Artikel *a = dynamic_cast<Artikel *>(b);

			nb->setNaam(b->getNaam());
			nb->setFabrikant(a->getFabrikant());
			nb->setPrijs(a->getPrijs());
			nb->setDiameter(a->getDiameter());
			nb->setType(a->getType());
			nb->setAantal(a->getAantal());

			this->addArtikel(nb);

			inBanden.read(reinterpret_cast<char *>(b), sizeof(Band));
		}
	}

	//klanten

	std::ifstream inKlanten("data/klanten.dat", ios::binary);

	if (!inKlanten)
	{
		cerr << "File could not be opened. - banden" << endl;
	}
	else {

		Klant * k = new Klant;

		inKlanten.read(reinterpret_cast<char *>(k), sizeof(Klant));

		while (inKlanten && !inKlanten.eof())
		{

			this->addClient(k);

			k = new Klant;

			inKlanten.read(reinterpret_cast<char *>(k), sizeof(Band));
		}
	}

	//bedrijfsklanten

	std::ifstream inCredit("data/bedrijfsklanten.dat", ios::binary);

	if (!inCredit)
	{
		cerr << "File could not be opened. - banden" << endl;
	}
	else {

		Bedrijfsklant * b = new Bedrijfsklant;

		inCredit.read(reinterpret_cast<char *>(b), sizeof(Bedrijfsklant));

		while (inCredit && !inCredit.eof())
		{

			Bedrijfsklant * nb = new Bedrijfsklant;

			nb->setBTWnummer(b->getBTWnummer());
			nb->setVolumekorting(b->getVolumekorting());
			nb->setBedrijfskorting(b->getBedrijfskorting());

			Klant *j = dynamic_cast<Klant *>(b);

			nb->setNaam(j->getNaam());
			nb->setAdres(j->getAdres());
			nb->setKorting(j->getKorting());
			nb->setBedrijf(j->getBedrijf());
			nb->setKorting2(j->getKorting2());

			this->addClient(nb);

			inCredit.read(reinterpret_cast<char *>(b), sizeof(Bedrijfsklant));
		}
	}

}

