#pragma once
#include <string>
#include <vector>

class Translator {
private:
    const std::string digits = "0123456789.";
    const std::string brackets = "()";

    std::string input;
    
    std::string join(std::vector<std::string>& parts);
public:
    Translator(const std::string& input);

    std::string translate();
};
