#include "Artist.h"

Artist::Artist()
{
}

Artist::~Artist()
{
}

Artist::Artist(std::string firstName, std::string secondName, std::string musicalInstrument, std::string gender, int rating, int yearOld)
	:firstName(firstName), secondName(secondName), gender(gender), musicalInstrument(musicalInstrument), rating(rating), yearOld(yearOld)
{
}

