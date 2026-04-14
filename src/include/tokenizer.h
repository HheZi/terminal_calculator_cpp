#ifndef TERMINAL_CALCULATOR_TOKENIZER_H
#define TERMINAL_CALCULATOR_TOKENIZER_H

#include <string>
#include <variant>
#include <vector>
#include "operation_token.h"

std::vector<std::variant<double, OperationToken> > splitExpression(const std::string &expression);

#endif //TERMINAL_CALCULATOR_TOKENIZER_H
