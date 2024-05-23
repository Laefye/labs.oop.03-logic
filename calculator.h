#pragma once
#include <vector>
#include <string>
#include "operators/operatorcreator.h"

class Calculator {
private:
    std::string expression;

    void split(std::vector<std::string>& parts);
public:
    Calculator(const std::string& expression);

    std::string calculate();
};
