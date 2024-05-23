#include "calculator.h"
#include "exceptions/unknownoperatorexception.h"
#include "iostream"

Calculator::Calculator(const std::string& expression) {
    this->expression = expression;
}

void Calculator::split(std::vector<std::string>& parts) {
    std::string expression = this->expression;
    size_t pos = 0;
    while ((pos = expression.find(' ')) != std::string::npos) {
        parts.push_back(expression.substr(0, pos));
        expression.erase(0, pos + 1);
    }
    parts.push_back(expression);
}

double Calculator::calculate() {
    OperatorCreator operatorCreator;
    std::vector<std::string> parts;
    split(parts);
    std::vector<double> stack;
    for (std::string& part : parts) {
        try
        {
            Operator* op = operatorCreator.create(part[0]);
            double value = op->execute(*stack.rbegin(), *(++stack.rbegin()));            
            delete op;
            stack.erase(stack.begin() + (stack.size() - 1));
            stack.erase(stack.begin() + (stack.size() - 1));
            stack.push_back(value);
        }
        catch(UnknownOperatorException& e)
        {
            stack.push_back(std::stold(part));
        }
    }
    return stack.empty() ? 0 : stack[0];
}
