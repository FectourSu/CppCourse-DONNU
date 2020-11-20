#include <iostream>
#include "Subtractor.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"
#include "Visitor.h"
void Loggable(ILoggable& s)
{
	s.logToScreen();
	s.logToFile("log.txt");
}

int main()
{
	double mass[]{ 2.5, -5, -3, 2.3, 10 };

	Subtractor s(2);
	s.setOperand(0, 23.65);
	s.setOperand(1, -12.15);
	

	Loggable(s);

	Multiplier m(4);
	m.setOperand(0, 2.5);
	m.setOperand(1, -3);
	m.setOperand(2, 4);
	m.setOperand(3, -1);

	Loggable(m);

	CustomExpressionEvaluator c;
	c.setOperands(mass, 5);
	c.shuffle();

	Loggable(c);


	/*Continue Lab2*/
	Visitor* firstPeople = new Visitor();
	firstPeople->visit();
	Visitor* secondPeople = new Visitor();
	secondPeople->visit();

}

