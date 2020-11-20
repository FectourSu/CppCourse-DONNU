#include "Artist.h"
Artist::~Artist()
{
}

void Artist::visit()
{
	this->rating = std::rand() % 5;
	this->concertCount++;
}

int Artist::getConcertCount()
{
	return this->concertCount;
}