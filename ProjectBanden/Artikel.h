#pragma once

#include <iomanip> 
#include <iostream>
#include <string>

using std::string;

using std::cout;
using std::cin;
using std::endl;

class Artikel
{
	public:
	
		//constructor & deconstructor
		Artikel();
		virtual ~Artikel();

		// getters
		string getNaam() const;
		string getFabrikant() const;
		double getPrijs() const;
		int getDiameter() const;
		string getType() const;
		int getAantal() const;
	
		// setters
		void setNaam(string);
		void setFabrikant(string);
		void setPrijs(double);
		void setDiameter(int);
		void setType(string);
		void setAantal(int);


		//print
		void print() const;

	private:
		string Naam;
		string Fabrikant;
		double Prijs;
		int Diameter;
		string Type;
		int Aantal;
};