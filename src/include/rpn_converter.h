#ifndef TERMINAL_CALCULATOR_RPN_CONVERTOR_H
#define TERMINAL_CALCULATOR_RPN_CONVERTOR_H

#include <queue>
#include <variant>
#include <vector>

#include "operation_token.h"

std::queue<std::variant<double, OperationToken>> convertToRPN(const std::vector<std::variant<double, OperationToken>> &tokens);

#endif //TERMINAL_CALCULATOR_RPN_CONVERTOR_H
