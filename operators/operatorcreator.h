#pragma once
#include <functional>
#include <vector>
#include <map>
#include <memory>
#include "exceptions/unknownoperatorexception.h"
#include "operator.h"
#include "add.h"
#include "minus.h"

class OperatorCreator {
private:
    std::map<char, std::function<Operator*()>> operators;
public:
    OperatorCreator();

    Operator* create(char character);
    int priority(char character);
};
