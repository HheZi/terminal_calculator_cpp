//
// Created by pavel on 4/5/26.
//

#ifndef TERMINAL_CALCULATOR_RPN_CALCULATOR_H
#define TERMINAL_CALCULATOR_RPN_CALCULATOR_H
#include <queue>
#include <variant>

#include "operation_token.h"

double calculateRPN(std::queue<std::variant<double, OperationToken>> &queue);

#endif //TERMINAL_CALCULATOR_RPN_CALCULATOR_H
