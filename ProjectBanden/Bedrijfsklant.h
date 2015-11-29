#pragma once
#include "Klant.h"
class Bedrijfsklant :
	public Klant
{
	public:
	
		//constructor & deconstructor
		Bedrijfsklant();
		virtual ~Bedrijfsklant();
	
		//getters
		string getBTWnummer() const;
		double getVolumekorting() const;
		double getBedrijfskorting() const;
	
		//setters
		void setBTWnummer(string);
		void setVolumekorting(int);
		void setBedrijfskorting(int);

		//print
		void print() const;
	
	private:
		string BTWnummer;
		double Volumekorting;
		double Bedrijfskorting;

};

