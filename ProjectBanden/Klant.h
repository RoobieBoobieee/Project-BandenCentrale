#pragma once

#include <iomanip> 
#include <iostream>
#include <string>

using std::string;

using std::cout;
using std::endl;
using std::cin;

class Klant
{
	public:

		//constructor en deconstructor
		Klant();
		Klant(char[], char[], int, char[], int);
		virtual ~Klant();

		//getters
		char* getNaam() ;
		char* getAdres() ;
		int getKorting() ;
		char* getBedrijf() ;
		int getKorting2() ;

		//setters
		void setNaam(char[]);
		void setAdres(char[]);
		void setKorting(int);
		void setBedrijf(char[]);
		void setKorting2(int);

		//print
		void print();

	private:
		char Naam[20];
		char Adres[64];
		int Korting;
		char Bedrijf[20];
		int Korting2;
};

