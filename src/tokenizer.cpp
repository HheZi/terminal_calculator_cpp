#include "include/tokenizer.h"

#include <memory>
#include <sstream>
#include <variant>

#include "include/number_token.h"
#include "include/operation_token.h"


std::vector<std::variant<NumberToken, OperationToken> > splitExpression(const std::string &expression) {
    std::vector<std::variant<NumberToken, OperationToken> > tokens{};

    std::stringstream ss{expression};

    std::string token;

    while (ss >> token) {
        bool is_number = true;
        for (size_t i = 0; i < token.size(); ++i) {
            char c = token[i];

            if (c == '-' && i == 0) {
                continue;
            }

            if (!std::isdigit(c) && c != '.') {
                is_number = false;
                break;
            }
        }

        if (is_number) {
            tokens.emplace_back(NumberToken{std::stod(token)});
        } else {
            if (token.length() > 1) {
                throw std::runtime_error{std::string{"Incorrect operator "} + token};
            }

            tokens.emplace_back(OperationToken::getOperationToken(token[0]));
        }
    }

    return tokens;
}
