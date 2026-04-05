#include "include/rpn_converter.h"
#include <queue>
#include <stack>
#include <stdexcept>

std::queue<std::variant<NumberToken, OperationToken> > convertToRPN(
    const std::vector<std::variant<NumberToken, OperationToken> > &tokens) {
    std::queue<std::variant<NumberToken, OperationToken> > output{};
    std::stack<OperationToken> operations{};

    for (const auto &token: tokens) {
        if (std::holds_alternative<NumberToken>(token)) {
            output.push(token);
        } else {
            const auto &operation_token = std::get<OperationToken>(token);

            if (operation_token.getType() == OperationToken::Type::LeftParen) {
                operations.push(operation_token);
            } else if (operation_token.getType() == OperationToken::Type::RightParen) {
                while (!operations.empty() && operations.top().getType() != OperationToken::Type::LeftParen) {
                    output.emplace(operations.top());
                    operations.pop();
                }
                if (operations.empty()) {
                    throw std::runtime_error{"Mismatcher parentheses"};
                }

                operations.pop();
            } else {
                while (!operations.empty()
                       && operations.top().getType() != OperationToken::Type::LeftParen
                       && (operations.top().getPrecendence() > operation_token.getPrecendence()
                           || (
                               operations.top().getPrecendence() == operation_token.getPrecendence() &&
                               operation_token.getIsLeftAssociative()
                           ))) {
                    output.emplace(operations.top());
                    operations.pop();
                }
                operations.push(operation_token);
            }
        }
    }

    while (!operations.empty()) {
        if (operations.top().getType() == OperationToken::Type::LeftParen) {
            throw std::runtime_error{"Mismatcher parentheses"};
        }

        output.emplace(operations.top());
        operations.pop();
    }

    return output;
}
