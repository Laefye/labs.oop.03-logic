#pragma once
#include <string>
#include "exceptions/invalidexpressionexception.h"

class Validator {
private:
    const std::string digits = "0123456789";
    const char point = '.';
    const std::string operators = "+-/*"; 
    const std::string brackets = "()";

    std::string expression;

    bool hasCharacterInNumber(std::size_t begin, char character);
public:
    Validator(const std::string& expression);

    void validate();
};
