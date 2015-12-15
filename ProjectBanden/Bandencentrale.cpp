#include "Bandencentrale.h"

//constructor en deconstructor
Bandencentrale::Bandencentrale()
{
}

Bandencentrale::~Bandencentrale()
{
}


//getters
 char* Bandencentrale::getNaam() 
{
	return this->Naam;
}

 char* Bandencentrale::getAdres() 
{
	return this->Adres;
}

vector<Klant*> * Bandencentrale::getKlanten() 
{
	return &Klanten;
}

vector<Artikel*> * Bandencentrale::getArtikels() 
{
	return &Artikels;
}

vector<Factuur*>* Bandencentrale::getFacturen()
{
	return &Facturen;
}


//setters
void Bandencentrale::setNaam(char s[])
{
	strcpy_s(this->Naam, s);
}

void Bandencentrale::setAdres(char s[])
{
	strcpy_s(this->Adres, s);
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

void Bandencentrale::addFactuur(Factuur * f)
{
	if (f == NULL) {
		Facturen.push_back(setupFactuur());
	}
	else
	{
		Facturen.push_back(f);
	}
}

//setup
void Bandencentrale::setupArtikel(Artikel * a)
{
	double dbl;
	int intgr;
	char str[20];

	cout << "Naam: ";
	cin.getline(str, 20);
	a->setNaam(str);

	cout << "Fabrikant: ";
	cin.getline(str, 20);
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

	int intgr;
	char str[20];

	cout << "Breedte: ";
	cin >> intgr;
	cin.get();
	b->setBreedte(intgr);

	cout << "Hoogte: ";
	cin >> intgr;
	cin.get();
	b->setHoogte(intgr);

	cout << "Snelheidsindex: ";
	cin.getline(str, 20);
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

	int intgr;
	char str[20];

	cout << "Breedte: ";
	cin >> intgr;
	cin.get();
	b->setBreedte(intgr);

	cout << "Kleur: ";
	cin.getline(str, 20);
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

	int intgr;
	char str[20];
	char adres[64];

	cout << "Naam: ";
	cin.getline(str, 20);
	k->setNaam(str);
	
	cout << "Adres: ";
	cin.getline(adres, 64);
	k->setAdres(adres);

	cout << "Korting: ";
	cin >> intgr;
	cin.get();
	k->setKorting(intgr);

	cout << "Korting 2: ";
	cin >> intgr;
	cin.get();
	k->setKorting2(intgr);

	k->setBedrijf("");
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

		int intgr;
		char str[20];
		char adres[64];

		cout << "Naam: ";
		cin.getline(str, 20);
		k->setNaam(str);

		cout << "Adres: ";
		cin.getline(adres, 64);
		k->setAdres(adres);

		cout << "Korting: ";
		cin >> intgr;
		cin.get();
		k->setKorting(intgr);

		cout << "Korting 2: ";
		cin >> intgr;
		cin.get();
		k->setKorting2(intgr);

		cout << "Bedrijf: ";
		cin.getline(str, 20);
		k->setBedrijf(str);

		cout << "BTW Nummer: ";
		cin.getline(str, 20);
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

Factuur * Bandencentrale::setupFactuur()
{
	Factuur* f = new Factuur;

	int intgr;
	char str[20];

	cout << "Factuurnummer: ";
	cin >> intgr;
	cin.get();
	f->setFactuurnummer(intgr);

	do
	{
		cout << "Naam van de klant: ";
		cin.getline(str, 20);

		intgr = searchClients(str);

		if (intgr >= 0)
		{
			f->setKlant(Klanten[intgr]);
			cout << "Klant toegevoegd!" << endl;
		}
		else
		{
			f->setKlant(NULL);
			cout << "Geen klant gevonden. Wilt u opnieuw proberen? (j/n)";
			cin.getline(str, 20);
			if (strcmp(str, "n"))
			{
				exit(1); //???
			}
		}
	} while (strcmp(str, "j") == 0);


	do
	{
		cout << "Naam van artikel dat u wilt toevoegen: ";
		cin.getline(str, 20);

		intgr = searchArticles(str);

		if (intgr >= 0)
		{
			f->addArtikel(Artikels[intgr]);
			Artikels[intgr]->setAantal(Artikels[intgr]->getAantal() - 1);
			cout << "Artikel toegevoegd!" << endl;
			cout << "Wilt u nog een artikel toevoegen? (j/n)";
			cin.getline(str, 20);
		}
		else
		{
			cout << "Geen artikel gevonden. Wilt u opnieuw proberen? (j/n)";
			cin.getline(str, 20);
		}
	} while (strcmp(str, "j") == 0);


	cout << "Korting: ";
	cin >> intgr;
	cin.get();
	f->setKorting(intgr);

	//dees ga nie werken heeee
	std::ofstream outCredit("data/facturen.dat", ios::app | ios::binary);

	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		system("pause");
		exit(1);
	}

	outCredit.write(reinterpret_cast< const char * >(f), sizeof(Factuur));

	return (f);
}


//print
void Bandencentrale::printClients()
{
	system("cls");

 	for (vector<Klant*>::iterator i = this->getKlanten()->begin(); i != this->getKlanten()->end(); ++i)
	{

		if (strcmp((*i)->getBedrijf(), "") == 0) {
			(*i)->print();

		} 
		else
		{
			Bedrijfsklant *bedrijfsklant = dynamic_cast<Bedrijfsklant *>(*i);
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

void Bandencentrale::printArticles(char s[]) 
{
	system("cls");

	for (vector<Artikel*>::iterator i = this->getArtikels()->begin(); i != this->getArtikels()->end(); ++i)
	{
		if (strcmp((*i)->getType(), s) == 0 || strcmp(s, "All") == 0) {

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
	}

	if (this->getArtikels()->size() == 0)
	{
		cout << "Er zijn geen artikels." << endl;
	}
	system("pause");
}

void Bandencentrale::printSizes()
{
	system("cls");

	for (vector<Artikel*>::iterator i = this->getArtikels()->begin(); i != this->getArtikels()->end(); ++i)
	{
		cout << (*i)->getDiameter() << " mm" << endl;
	}

	if (this->getArtikels()->size() == 0)
	{
		cout << "Er zijn geen artikels." << endl;
	}

	system("pause");
}

void Bandencentrale::printFacturen()
{
	system("cls");

	for (vector<Factuur*>::iterator i = this->getFacturen()->begin(); i != this->getFacturen()->end(); ++i)
	{
		(*i)->print();
	}

	system("pause");
}


//search

int Bandencentrale::searchArticles(char s[])
{
	int index = 0;
	for (vector<Artikel*>::const_iterator i = this->getArtikels()->cbegin(); i != this->getArtikels()->cend(); ++i)
	{
		if (strcmp((*i)->getNaam(), s) == 0)
		{
			return (index);
		}
		index++;
	}

	return -1;
}

int Bandencentrale::searchClients(char s[])
{
	int index = 0;
	for (vector<Klant*>::const_iterator i = this->getKlanten()->cbegin(); i != this->getKlanten()->cend(); ++i)
	{
		if (strcmp((*i)->getNaam(), s) == 0)
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
	char str[20];
	int index = 0;
	do
	{
		cout << "Naam van artikel dat u wilt verwijderen: ";
		cin.getline(str, 20);

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
			cin.getline(str, 20);
		}
	} while (strcmp(str, "j") && index < 0);

}

void Bandencentrale::removeClient()
{
	char str[20];
	int index = 0;
	do
	{
		cout << "Naam van de klant die u wilt verwijderen: ";
		cin.getline(str, 20);

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
			cin.getline(str, 20);
		}
	} while (strcmp(str, "j") && index < 0);

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

			inKlanten.read(reinterpret_cast<char *>(k), sizeof(Klant));
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
			nb->setVolumekorting(int(b->getVolumekorting() * 100));
			nb->setBedrijfskorting(int(b->getBedrijfskorting() * 100));

			Klant *j = dynamic_cast<Klant *>(b);

			nb->setNaam(j->getNaam());
			nb->setAdres(j->getAdres());
			nb->setKorting(int(j->getKorting() * 100));
			nb->setBedrijf(j->getBedrijf());
			nb->setKorting2(int(j->getKorting2() * 100));

			this->addClient(nb);

			inCredit.read(reinterpret_cast<char *>(b), sizeof(Bedrijfsklant));
		}
	}


	//facturen

	std::ifstream inFacturen("data/facturen.dat", ios::binary);

	if (!inFacturen)
	{
		cerr << "File could not be opened. - facturen" << endl;
	}
	else {

		Factuur * f = new Factuur;

		inKlanten.read(reinterpret_cast<char *>(f), sizeof(Factuur));

		while (inFacturen && !inFacturen.eof())
		{

			this->addFactuur(f);

			f = new Factuur;

			inFacturen.read(reinterpret_cast<char *>(f), sizeof(Factuur));
		}
	}

}

