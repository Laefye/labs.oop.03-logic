#include <iostream>
#include "translator.h"

int main() {
    Translator translator("2+(2-3)");
    translator.translate();
}
