#pragma once

#include <string>

using std::string;

class Klant
{
	public:

		//constructor en deconstructor
		Klant();
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
		void setKorting(double);
		void setBedrijf(string);
		void setKorting2(double);

	private:
		string Naam;
		string Adres;
		double Korting;
		string Bedrijf;
		double Korting2;
};

