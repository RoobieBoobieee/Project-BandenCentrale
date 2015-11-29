#include "Bandencentrale.h"


int login();
int articles();
int addarticle();
int addtire();
int addrim();
int showarticles(string);

using std::cout;
using std::cin;
using std::endl;

Bandencentrale BC;

int main()
{

	int id = login();
	
	int keuze = 0;

	do
	{
		system("cls");
		cout << "##########################################################################" << endl;
		cout << "#                                                        Logged In As: " << id << " #" << endl;
		cout << "#    1. Artikels Bekijken                                                #" << endl;
		cout << "#    2. Artikel Toevoegen                                                #" << endl;
		cout << "#    3. Artikel Verwijderen                                              #" << endl;
		cout << "#    4. Klanten Bekijken                                                 #" << endl;
		cout << "#    9. Stoppen                                                          #" << endl;
		cout << "#                                                                        #" << endl;
		cout << "##########################################################################" << endl;
		cout << endl;
		cout << "> ";
		cin >> keuze;
		cin.get();
		switch (keuze)
		{
		case 1:
			articles();
			break;

		case 2:
			addarticle();
			break;

		case 3:
			break;

		case 9: 
			cout << "Programma stoppen ..." << endl;
			break;

		default: 
			cout << "Ongeldige keuze ..." << endl;
			cin.get();
			system("pause");
			break;

		}
	} while (keuze != 9);

	return 0;
}

int login()
{
	int id = 0;

	do
	{
		system("cls");
		cout << "##########################################################################" << endl;
		cout << "#                                                                        #" << endl;
		cout << "#    1. Eigenaar                                                         #" << endl;
		cout << "#    2. Personeelslid                                                    #" << endl;
		cout << "#    9. Stoppen                                                          #" << endl;
		cout << "#                                                                        #" << endl;
		cout << "##########################################################################" << endl;
		cout << endl;
		cout << "> ";
		cin >> id;
		cin.get();
		switch (id)
		{
		case 1:
			return 1;
			break;

		case 2:
			return 2;
			break;

		case 9:
			cout << "Programma stoppen ..." << endl;
			system("pause");
			exit(1);

		default:
			cout << "Ongeldige keuze" << endl;
			break;

		}
	} while (1);

	return 0;

}

int articles()
{
	int choice = 0;

	do
	{
		system("cls");
		cout << "##########################################################################" << endl;
		cout << "#                                                                        #" << endl;
		cout << "#    1. Artikels Bekijken                                                #" << endl;
		cout << "#    2. Banden Bekijken                                                  #" << endl;
		cout << "#    3. Velgen Bekijken                                                  #" << endl;
		cout << "#    4. Maten Bekijken                                                   #" << endl;
		cout << "#    5. Terug                                                            #" << endl;
		cout << "#    9. Stoppen                                                          #" << endl;
		cout << "#                                                                        #" << endl;
		cout << "##########################################################################" << endl;
		cout << endl;
		cout << "> ";
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 1:
			showarticles("all");
			break;
		case 2:
			showarticles("Band");
			break;
		case 3:
			showarticles("Velg");
			break;
		case 4:
			break;
		case 5:
			return 0;
		case 9:
			cout << "Programma stoppen ..." << endl;
			system("pause");
			exit(1);
		default:
			cout << "Ongeldige keuze ..." << endl;
			cin.get();
			system("pause");
			break;
		}
	} while (choice != 5);

	return 1;
}

int showarticles(string s)
{

	for (vector<Artikel*>::const_iterator i = BC.getArtikels()->cbegin(); i != BC.getArtikels()->cend(); ++i)
	{
		system("cls");

		if ((*i)->getType().compare(s) == 0 || s.compare("all") == 0) {
			
			(*i)->print();
			
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
	system("pause");
	return 1;
}

int addarticle()
{
	int choice = 0;

	do
	{
		cout << "Wilt u een band (1) of een velg (2) toevoegen? " << endl;
		cout << "> ";
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 1:
			choice = addtire();
			break;
		case 2:
			choice = addrim();
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "Ongeldige keuze ..." << endl;
			cin.get();
			system("pause");
			break;
		}
	} while (choice < 1 && choice > 3);


	return 1;
}

int addtire()
{
	Band* article = new Band;

	string str;
	double dbl;
	int intgr;

	cout << "Naam: ";
	getline(std::cin, str);
	article->setNaam(str);

	cout << "Fabrikant: ";
	getline(cin, str);
	article->setFabrikant(str);

	cout << "Prijs: ";
	cin >> dbl;
	article->setPrijs(dbl);

	cout << "Diameter (mm): ";
	cin >> intgr;
	article->setDiameter(intgr);

	article->setType("Band");

	cout << "Aantal: ";
	cin >> intgr;
	article->setAantal(intgr);

	cout << "Breedte (mm): ";
	cin >> intgr;
	article->setBreedte(intgr);

	cout << "Hoogte (mm): ";
	cin >> intgr;
	article->setHoogte(intgr);

	cout << "Snelheidsindex: ";
	cin >> str;
	article->setSnelheidsindex(str);

	cout << "Seizoen (Zomer=0; Winter = 1): ";
	cin >> intgr;
	article->setSeizoen(intgr);

	BC.addArtikel(article);

	return 1;
}

int addrim()
{
	Velg* article = new Velg;

	string str;
	double dbl;
	int intgr;

	cout << "Naam: ";
	getline(cin, str);
	article->setNaam(str);

	cout << "Fabrikant: ";
	getline(cin, str);
	article->setFabrikant(str);

	cout << "Prijs: " ;
	cin >> dbl;
	article->setPrijs(dbl);

	cout << "Diameter (mm): " ;
	cin >> intgr;
	article->setDiameter(intgr);

	article->setType("Velg");

	cout << "Aantal: " << endl;
	cin >> intgr;
	article->setDiameter(intgr);

	cout << "Breedte (mm): ";
	cin >> intgr;
	article->setBreedte(intgr);

	cout << "Kleur: ";
	cin >> str;
	article->setKleur(str);

	cout << "Aluminium: (Nee=0; Ja=1)" << endl;
	cin >> intgr;
	article->setAluminium(intgr);

	BC.addArtikel(article);

	return 1;
}