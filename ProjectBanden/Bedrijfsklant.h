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
		string getBTWnummer();
		double getVolumekorting();
		double getBedrijfskorting();
	
		//setters
		void setBTWnummer(string);
		void setVolumekorting(double);
		void setBedrijfskorting(double);
	
	private:
		string BTWnummer;
		double Volumekorting;
		double Bedrijfskorting;

};

