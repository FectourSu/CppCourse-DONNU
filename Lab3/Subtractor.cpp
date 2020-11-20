#include "Subtractor.h"

Subtractor::Subtractor()
    :ExpressionEvaluator::ExpressionEvaluator()
{
}

Subtractor::Subtractor(size_t n)
    :ExpressionEvaluator::ExpressionEvaluator(n)
{
}

void Subtractor::logToScreen()
{
    std::cout << this->joinOperands(" - ") << " = " << this->calculate() << "\n";
}

void Subtractor::logToFile(const std::string& fileName)
{
    std::string str = this->joinOperands(" - ");

    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);
    ofs << str + " = " + std::to_string(this->calculate()) + "\n";
    ofs.close();
}

double Subtractor::calculate()
{
    double result = 0;

    for (size_t i = 0; i < this->countOperands; i++)
        if(operands[i] < 0)
            result += this->operands[i];
        else
            result -= this->operands[i];

    return result;
}
