#include "Visitor.h"
#include <fstream>

Visitor::~Visitor()
{
}
Visitor::Visitor()
{
	this->countVisitor++;
}

void Visitor::visit()
{
	takeThePlace();
}

void Visitor::takeThePlace()
{
	int countPlace = countVisitor;
	int temp = 0;
	std::ifstream f("countPlace.txt");
	std::ofstream f0("countPlace.txt", std::fstream::binary | std::fstream::out | std::fstream::in);

	f >> temp;
	f0 << temp - countPlace;
	
	f0.close();
}