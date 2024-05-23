#include "operatorcreator.h"

OperatorCreator::OperatorCreator() {
    operators['+'] = []() {
        return new Add();
    };
    operators['-'] = []() {
        return new Minus();
    };
}

Operator* OperatorCreator::create(char character) {
    if (!operators.count(character)) {
        throw UnknownOperatorException();
    }
    return operators[character]();
}

int OperatorCreator::priority(char character) {
    Operator* op = create(character);
    int priority = op->priority();
    delete op;
    return priority;
}
