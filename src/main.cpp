#include "include/tokenizer.h"
#include "include/rpn_converter.h"
#include "include/rpn_calculator.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    while (true) {
        std::string expression{};

        std::cout << "Enter expression(to quit enter /q): ";
        std::getline(std::cin >> std::ws, expression);

        if (expression == "/q") {
            break;
        }

        try {
            const std::vector<std::variant<NumberToken, OperationToken> > &tokens = splitExpression(expression);

            std::queue<std::variant<NumberToken, OperationToken> > rpn = convertToRPN(tokens);

            const double result = calculateRPN(rpn);

            std::cout << "Result is " << result << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
