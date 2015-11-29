#pragma once

#include <string>
#include <vector>

#include "Klant.h"

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
		void setKlanten(vector<Klant*>);
		void setArtikels(vector<Artikel*>);
		void addArtikel(Artikel *);

	private:
		string naam;
		string Adres;
		vector<Klant*> Klanten;
		vector<Artikel*> Artikels;

};

