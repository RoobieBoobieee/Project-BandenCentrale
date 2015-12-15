#pragma once

#include "Klant.h"

class Bedrijfsklant :
	public Klant
{
	public:
	
		//constructor & deconstructor
		Bedrijfsklant();
		Bedrijfsklant(char[], char[], double, char[], double, char[], double, double);
		virtual ~Bedrijfsklant();
	
		//getters
		 char* getBTWnummer() ;
		double getVolumekorting() ;
		double getBedrijfskorting() ;
	
		//setters
		void setBTWnummer(char[]);
		void setVolumekorting(double);
		void setBedrijfskorting(double);

		//print
		void print();
	
	private:
		char BTWnummer[20];
		double Volumekorting;
		double Bedrijfskorting;

};

