#include "include/operation_token.h"

#include <stdexcept>
#include<cmath>

OperationToken OperationToken::getOperationToken(const char token) {
    switch (token) {
        case '+':
            static OperationToken add{Type::Add, '+', 0, true, [](double a, double b) { return a + b; }};
            return add;
        case '-':
            static OperationToken substruct{Type::Subtract, '-', 0, true, [](double a, double b) { return a - b; }};
            return substruct;
        case '*':
            static OperationToken multiply{Type::Multiply, '*', 1, true, [](double a, double b) { return a * b; }};
            return multiply;
        case '/':
            static OperationToken divide{Type::Divide, '/', 1, true, [](double a, double b) { return a / b; }};
            return divide;
        case '^':
            static OperationToken exponent{
                Type::Exponent, '^', 1, false, [](double a, double b) { return std::pow(a, b); }
            };
            return exponent;
        case '(':
            static OperationToken left_paren{Type::LeftParen, '(', 2, true, nullptr};
            return left_paren;
        case ')':
            static OperationToken right_paren{Type::RightParen, ')', 2, true, nullptr};
            return right_paren;
        default: throw std::runtime_error{std::string{"Unexpected value: "} + token};
    }
}

