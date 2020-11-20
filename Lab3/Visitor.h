#pragma once
#include "Person.h"
#include <ctime>
#include "IVisitor.h"
class Visitor : public Person, public IVisitor
{
	void takeThePlace();
	int countVisitor = 0;
public:
	Visitor();
	~Visitor();

	void visit() override;
};

