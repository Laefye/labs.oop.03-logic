#include "translator.h"
#include <iostream>
#include "operators/operatorcreator.h"

Translator::Translator(const std::string& input) {
    this->input = input;
} 

std::string Translator::join(std::vector<std::string>& parts) {
    std::string result = "";
    for (std::size_t i = 0; i < parts.size(); i++)
    {
        result += parts[i];
        result += ' ';
    }
    return result;
}

void Translator::translate() {
    OperatorCreator operatorCreator;
    std::vector<std::string> output;
    std::vector<std::string> stack;
    bool makeNumber = true;
    for (std::size_t i = 0; i < input.length(); i++)
    {
        if (digits.find(input[i]) != std::string::npos && makeNumber) {
            makeNumber = false;
            output.push_back(std::string{input[i]});
        } else if (digits.find(input[i]) != std::string::npos) {
            output.rbegin()->push_back(input[i]);
        } else if (brackets.find(input[i]) != std::string::npos) {
            if (input[i] == '(') {
                stack.push_back(std::string{input[i]});
            } else {
                while (stack.rbegin()->at(0) != '(') {
                    output.push_back(*stack.rbegin());
                    stack.erase(stack.begin() + (stack.size() - 1));
                }
                stack.erase(stack.begin() + (stack.size() - 1));
            }
        } else {
            makeNumber = true;
            if (stack.empty() || stack.rbegin()->at(0) == '(') {
                stack.push_back(std::string{input[i]});
            } else if (operatorCreator.priority(input[i]) <= operatorCreator.priority(stack.rbegin()->at(0))) {
                output.push_back(*stack.rbegin());
                stack.erase(stack.begin() + (stack.size() - 1));
                stack.push_back(std::string{input[i]});
            }
        }
    }
    for (std::string& part : stack) {
        output.push_back(part);
    }
    std::cout << join(output) << std::endl;
}
