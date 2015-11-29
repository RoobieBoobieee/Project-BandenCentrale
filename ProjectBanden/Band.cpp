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
void Band::setBreedte(int i)
{
	if (i < 0)
	{
		Breedte = 0;
	}
	else
	{
		Breedte = i;
	}
}

void Band::setHoogte(int i)
{
	if (i < 0)
	{
		Hoogte = 0;
	}
	else
	{
		Hoogte = i;
	}
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

