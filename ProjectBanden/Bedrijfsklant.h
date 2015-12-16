#pragma once

#include "Klant.h"

class Bedrijfsklant :
	public Klant
{
	public:
	
		//constructor & deconstructor
		Bedrijfsklant();
		Bedrijfsklant(char[], char[], int, char[], int, char[], int, int);
		virtual ~Bedrijfsklant();
	
		//getters
		 char* getBTWnummer() ;
		int getVolumekorting() ;
		int getBedrijfskorting() ;
	
		//setters
		void setBTWnummer(char[]);
		void setVolumekorting(int);
		void setBedrijfskorting(int);

		//print
		void print();
	
	private:
		char BTWnummer[20];
		int Volumekorting;
		int Bedrijfskorting;

};

