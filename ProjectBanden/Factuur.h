#pragma once

#include <vector>

#include "Klant.h"
#include "Artikel.h"

#include "Band.h"
#include "Velg.h"

using std::vector;

class Factuur
{
	public:
	
		//constructor en deconstructor
		Factuur();
		virtual ~Factuur();
			
		//getters 
		int getFactuurnummer() const;
		Klant const* getKlant() const;
		vector<Artikel*> const * getArtikels() const;
		double getTotaalprijs() const;
		double getKorting() const;

		//setters
		void setFactuurnummer(int);
		void setKlant(Klant *);
		void setArtikels(vector<Artikel*>);
		void setTotaalprijs(double);
		void setKorting(int);
		void addArtikel(Artikel *);


	private:
		int Factuurnummer;
		Klant *_Klant; //y u do dis
		vector<Artikel*> Artikels;
		double Totaalprijs;
		double Korting;

		//setters
		void addTotaalprijs(double); //totaalprijs wordt intern berekend zodat er niet gefoefeld kan worden
};

