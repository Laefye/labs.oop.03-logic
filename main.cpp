#include <iostream>
#include "facade.h"

int main() {
    std::cout << Facade().calculate("3+5") << std::endl;
}
