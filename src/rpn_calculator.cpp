#include "include/rpn_calculator.h"

#include <stack>
#include <stdexcept>

double calculateRPN(std::queue<std::variant<double, OperationToken> > &queue) {
    std::stack<double> stack{};

    while (!queue.empty()) {
        const std::variant<double, OperationToken> &variant = queue.front();

        if (std::holds_alternative<double>(variant)) {
            const auto &number = std::get<double>(variant);
            stack.push(number);
        } else {
            const auto &operation = std::get<OperationToken>(variant);

            const double rightOperand = stack.top();
            stack.pop();
            const double leftOperand = stack.top();
            stack.pop();

            double result = operation.getFunc()(leftOperand, rightOperand);

            stack.push(result);
        }

        queue.pop();
    }

    if (stack.empty()) {
        throw std::runtime_error{"Wrong expression"};
    }

    return stack.top();
}
