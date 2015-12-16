#pragma once

#include <vector>

#include "Bedrijfsklant.h"

#include "Band.h"
#include "Velg.h"

#include "Factuur.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using std::vector;

using std::cerr;
using std::endl;
using std::ios;

class Bandencentrale
{
	public:

		//constructor en deconstructor
		Bandencentrale();
		virtual ~Bandencentrale();

		//getters
		char* getNaam() ;
		char* getAdres() ;
		vector<Klant*>  * getKlanten() ;
		vector<Artikel*>  * getArtikels();
		vector<Factuur*>  * getFacturen();
		
		//setters
		void setNaam(char[]);
		void setAdres(char[]);
		void setKlanten(vector<Klant*>);
		void setArtikels(vector<Artikel*>);

		//add
		void addArtikel(Artikel * optional = NULL);
		void addClient(Klant * optional = NULL);
		void addFactuur(Factuur * optional = NULL);

		//setup
		Klant * setupKlant();
		void setupArtikel(Artikel *);
		Artikel * setupBand();
		Artikel * setupVelg();
		Klant * setupBedrijfsklant();
		Factuur * setupFactuur();


		//print
		void printClients();
		void printArticles(char[]);
		void printSizes();
		void printFacturen();

		//search
		int searchArticles(char[]);
		int searchClients(char[]);

		//remove
		void removeArticle();
		void removeClient();

		//read
		void readData();

	private:
		char Naam[20];
		char Adres[64];
		vector<Klant*> Klanten;
		vector<Artikel*> Artikels;
		vector<Factuur*> Facturen;

};

