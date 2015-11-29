#include "Band.h"

//constructor en deconstructor
Band::Band()
{
}

Band::~Band()
{
}

//getters
int Band::getBreedte() const
{
	return Breedte;
}

int Band::getHoogte() const
{
	return Hoogte;
}

string Band::getSnelheidsindex() const
{
	return Snelheidsindex;
}

string Band::getSeizoen() const
{
	return Seizoen;
}

//setters
void Band::setBreedte(int b)
{
	Breedte = b;
}

void Band::setHoogte(int h)
{
	Hoogte = h;
}

void Band::setSnelheidsindex(string s)
{
	Snelheidsindex = s;
}

void Band::setSeizoen(int i)
{
	if (i == 1)
	{
		Seizoen = "Winter";
	}
	else
	{
		Seizoen = "Zomer";
	}
}

