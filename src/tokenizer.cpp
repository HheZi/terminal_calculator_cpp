#include "include/tokenizer.h"

#include <memory>
#include <sstream>
#include <variant>

#include "include/operation_token.h"


std::vector<std::variant<double, OperationToken> > splitExpression(const std::string &expression) {
    std::vector<std::variant<double, OperationToken> > tokens{};

    std::stringstream ss{expression};

    std::string token;

    while (ss >> token) {
        bool is_number = false;
        for (size_t i = 0; i < token.size(); ++i) {
            char c = token[i];

            if (c == '-' && i == 0) {
                continue;
            }

            is_number = std::isdigit(c) || c == '.';
        }

        if (is_number) {
            tokens.emplace_back(std::stod(token));
        } else {
            if (token.length() > 1) {
                throw std::runtime_error{std::string{"Incorrect operator "} + token};
            }

            tokens.emplace_back(OperationToken::getOperationToken(token[0]));
        }
    }

    return tokens;
}
