#include <iostream>
#include "facade.h"

int main() {
    std::cout << Facade().calculate("3+4*2/(1-5)") << std::endl;
}
