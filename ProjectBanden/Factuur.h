#pragma once


#include "Klant.h"

#include "Band.h"
#include "Velg.h"

class Factuur
{
public:

	//constructor en deconstructor
	Factuur();
	virtual ~Factuur();

	//getters
	int getFactuurnummer();
	Klant getKlant();

	
};

