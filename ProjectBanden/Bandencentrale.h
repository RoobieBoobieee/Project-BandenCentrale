#pragma once

#include <vector>

#include "Bedrijfsklant.h"

#include "Band.h"
#include "Velg.h"

using std::string;
using std::vector;

class Bandencentrale
{
	public:

		//constructor en deconstructor
		Bandencentrale();
		virtual ~Bandencentrale();

		//getters
		string getNaam() const;
		string getAdres() const;
		vector<Klant*> const * getKlanten() const;
		vector<Artikel*> const * getArtikels() const;
		
		//setters
		void setNaam(string);
		void setAdres(string);
		void setKlanten(vector<Klant*>);  //wordt nog niet gebruikt
		void setArtikels(vector<Artikel*>);  //wordt nog niet gebruikt

		//add
		void addArtikel(Artikel * optional = NULL);
		void addClient(Klant * optional = NULL);

		//setup
		Klant * setupKlant(Klant * optional = NULL);
		void setupArtikel(Artikel *);
		Artikel * setupBand();
		Artikel * setupVelg();
		Klant * setupBedrijfsklant();

		//print
		void printClients() const;
		void printArticles(string optional = "All") const;
		void printSizes() const;

		//search
		int searchArticles(string);
		int searchClients(string);

		//remove
		void removeArticle();
		void removeClient();

	private:
		string naam;
		string Adres;
		vector<Klant*> Klanten;
		vector<Artikel*> Artikels;

};

