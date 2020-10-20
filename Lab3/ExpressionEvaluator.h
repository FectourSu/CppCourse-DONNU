#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "ILoggable.cpp"

class ExpressionEvaluator : public ILoggable
{
protected:
	size_t countOperands;
	double* operands;

	std::string outOperands(std::string operands);

public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual ~ExpressionEvaluator();

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;


	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
};