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
		char* getNaam() ;
		char* getFabrikant() ;
		double getPrijs() ;
		int getDiameter() ;
		char* getType() ;
		int getAantal();
	
		// setters
		void setNaam(char[]);
		void setFabrikant(char[]);
		void setPrijs(double);
		void setDiameter(int);
		void setType(char[]);
		void setAantal(int);

		//print
		void print();

	private:
		char Naam[20];
		char Fabrikant[20];
		double Prijs;
		int Diameter;
		char Type[5];
		int Aantal;
};