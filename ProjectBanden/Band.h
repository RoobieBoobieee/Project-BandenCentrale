#pragma once
#include "Artikel.h"
class Band :
	public Artikel
{
	public:

		//constructor & deconstructor
		Band();
		virtual ~Band();

		//getters
		int getBreedte() const;
		int getHoogte() const;
		string getSnelheidsindex() const;
		string getSeizoen() const;
	
		//setters
		void setBreedte(int);
		void setHoogte(int);
		void setSnelheidsindex(string);
		void setSeizoen(int);

	private:
		int Breedte;
		int Hoogte;
		string Snelheidsindex;
		string Seizoen;
};

