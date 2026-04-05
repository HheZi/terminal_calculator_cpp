#ifndef TERMINAL_CALCULATOR_RPN_CONVERTOR_H
#define TERMINAL_CALCULATOR_RPN_CONVERTOR_H

#include <queue>
#include <variant>
#include <vector>

#include "number_token.h"
#include "operation_token.h"

std::queue<std::variant<NumberToken, OperationToken>> convertToRPN(const std::vector<std::variant<NumberToken, OperationToken>> &tokens);

#endif //TERMINAL_CALCULATOR_RPN_CONVERTOR_H
