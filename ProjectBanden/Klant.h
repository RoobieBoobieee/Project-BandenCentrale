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
		Klant(string, string, double, string, double);
		virtual ~Klant();

		//getters
		string getNaam() const;
		string getAdres() const;
		double getKorting() const;
		string getBedrijf() const;
		double getKorting2() const;

		//setters
		void setNaam(string);
		void setAdres(string);
		void setKorting(int);
		void setBedrijf(string);
		void setKorting2(int);

		//print
		void print() const;

	private:
		string Naam;
		string Adres;
		double Korting;
		string Bedrijf;
		double Korting2;
};

