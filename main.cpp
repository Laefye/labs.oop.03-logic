#include <iostream>
#include "translator.h"
#include "calculator.h"

int main() {
    Translator translator("3+4*2/(1-5)");
    Calculator calculator(translator.translate());
    std::cout << calculator.calculate() << std::endl;
}
