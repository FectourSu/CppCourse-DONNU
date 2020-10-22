#pragma once
#include "ExpressionEvaluator.h"

class Subtractor : public ExpressionEvaluator
{
public:

	Subtractor();
	Subtractor(size_t n);

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	double calculate() override;

	//void shuffle() override;
	//void shuffle(size_t i, size_t j) override;
};

