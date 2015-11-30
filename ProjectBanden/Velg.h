#pragma once

#include "Artikel.h"

class Velg :
	public Artikel
{
	public:
	
		//constructor & deconstructor
		Velg();
		virtual ~Velg();
	
		//getters
		int getBreedte() const;
		string getKleur() const;
		bool getAluminium() const;
	
		//setters
		void setBreedte(int);
		void setKleur(string);
		void setAluminium(int);

		//print
		void print() const;
	
	private:
		int Breedte;
		string Kleur;
		bool Aluminium;
};

