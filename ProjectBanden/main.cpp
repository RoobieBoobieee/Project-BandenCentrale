#include "Bandencentrale.h"


int login();
int articlesmenu();

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

		cout << "##############################################################################" << endl;
		cout << "#                                                            Logged In As: " << id << " #" << endl;
		cout << "#    1. Artikels Bekijken                                                    #" << endl;
		cout << "#    2. Artikel Toevoegen                                                    #" << endl;
		cout << "#    3. Artikel Verwijderen                                                  #" << endl;
		cout << "#    4. Klanten Bekijken                                                     #" << endl;
		cout << "#    5. Klant Toevoegen                                                      #" << endl;
		cout << "#    6. Klant Verwijderen                                                    #" << endl;
		cout << "#    7. Factuuur Aanmaken                                                    #" << endl;
		cout << "#    8. uitlezen test                                                    #" << endl;
		cout << "#    9. Stoppen                                                              #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
		cout << "> ";

		cin >> keuze;
		cin.get();

		switch (keuze)
		{
		case 1:
			articlesmenu();
			break;

		case 2:
			BC.addArtikel();
			break;

		case 3:
			BC.removeArticle();
			break;

		case 4:
			BC.printClients();
			break;

		case 5:
			BC.addClient();
			break;

		case 6:
			BC.removeClient();
			break;

		case 7:

			break;

		case 8:
			BC.readData();
			break;

		case 9: 
			cout << "Programma stoppen ..." << endl;
			break;

		default: 
			cout << "Ongeldige keuze ..." << endl;
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

		cout << "##############################################################################" << endl;
		cout << "#                                                                            #" << endl;
		cout << "#    1. Eigenaar                                                             #" << endl;
		cout << "#    2. Personeelslid                                                        #" << endl;
		cout << "#    9. Stoppen                                                              #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
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

int articlesmenu()
{
	int choice = 0;

	do
	{
		system("cls");

		cout << "##############################################################################" << endl;
		cout << "#                                                                            #" << endl;
		cout << "#    1. Alle Artikels Bekijken                                               #" << endl;
		cout << "#    2. Banden Bekijken                                                      #" << endl;
		cout << "#    3. Velgen Bekijken                                                      #" << endl;
		cout << "#    4. Maten Bekijken                                                       #" << endl;
		cout << "#    5. Terug                                                                #" << endl;
		cout << "#    9. Stoppen                                                              #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
		cout << "> ";

		cin >> choice;
		cin.get();

		switch (choice)
		{
			case 1:
				BC.printArticles();
				break;
			case 2:
				BC.printArticles("Band");
				break;
			case 3:
				BC.printArticles("Velg");
				break;
			case 4:
				BC.printSizes();
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