#include <iostream>
#include "translator.h"

int main() {
    Translator translator("3.3+4*2/(1-5)");
    std::cout << translator.translate() << std::endl;
}
