#pragma once

#include "Artikel.h"

class Velg :
	public Artikel
{
	public:
	
		//constructor & deconstructor
		Velg();
		Velg(char[], char[], double, int, char[], int, int, char[], bool);
		virtual ~Velg();
	
		//getters
		int getBreedte() ;
		char* getKleur() ;
		bool getAluminium() ;
	
		//setters
		void setBreedte(int);
		void setKleur(char[]);
		void setAluminium(int);

		//print
		void print();
	
	private:
		int Breedte;
		char Kleur[20];
		bool Aluminium;
};

