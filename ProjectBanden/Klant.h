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
		Klant(char[], char[], double, char[], double);
		virtual ~Klant();

		//getters
		 char* getNaam() ;
		 char* getAdres() ;
		double getKorting() ;
		 char* getBedrijf() ;
		double getKorting2() ;

		//setters
		void setNaam(char[]);
		void setAdres(char[]);
		void setKorting(double);
		void setBedrijf(char[]);
		void setKorting2(double);

		//print
		void print();

	private:
		char Naam[20];
		char Adres[64];
		double Korting;
		char Bedrijf[20];
		double Korting2;
};

