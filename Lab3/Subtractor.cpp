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
    double result = NULL;

    for (size_t i = 0; i < this->countOperands; i++)
        result -= this->operands[i];

    return result;
}

//void Subtractor::shuffle()
//{
//}
//
//void Subtractor::shuffle(size_t i, size_t j)
//{
//}
