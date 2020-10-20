#include "ExpressionEvaluator.h"

inline ExpressionEvaluator::ExpressionEvaluator()
	: ExpressionEvaluator::ExpressionEvaluator(20)
{
}

inline ExpressionEvaluator::ExpressionEvaluator(size_t n)
{
	this->countOperands = n;

	this->operands = new double[this->countOperands];

	memset(this->operands, 0, this->countOperands);
}

inline ExpressionEvaluator::~ExpressionEvaluator()
{
	delete[] this->operands;
}

void ExpressionEvaluator::logToScreen()
{
	for (size_t i = 0; i < this->countOperands; i++)
		std::cout << this->operands[i] << ";";
}

void ExpressionEvaluator::logToFile(const std::string fileName)
{
	std::string str;

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i];
		str += "; ";
	}

	std::ofstream ofs(fileName, std::ofstream::out);
	ofs << str;
	ofs.close();
}


inline void ExpressionEvaluator::setOperand(size_t pos, double value)
{
	if (pos < 0 || pos >= this->countOperands)
		throw std::exception("Argument out of range");

	this->operands[pos] = value;
}

inline void ExpressionEvaluator::setOperands(double ops[], size_t n)
{
	if (this->operands)
		delete[] this->operands;

	this->operands = new double[n];

	std::memcpy(this->operands, ops, sizeof(double) * n);

	this->countOperands = n;
}