#pragma once
#include "Artikel.h"

class Band :
	public Artikel
{
	public:
		//constructor & deconstructor
		Band();
		Band(char[], char[], double, int, char[], int, int, int, char[], bool);
		virtual ~Band();

		//getters
		int getBreedte() ;
		int getHoogte() ;
		char* getSnelheidsindex() ;
		char* getSeizoen() ;
		int getSeizoenint() ;
	
		//setters
		void setBreedte(int);
		void setHoogte(int);
		void setSnelheidsindex(char[]);
		void setSeizoen(int);
		
		//print
		void print();

	private:
		int Breedte;
		int Hoogte;
		char Snelheidsindex[5];
		char Seizoen[6];
};

