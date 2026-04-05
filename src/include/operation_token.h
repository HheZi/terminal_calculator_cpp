#ifndef TERMINAL_CALCULATOR_OPERATION_TOKEN_H
#define TERMINAL_CALCULATOR_OPERATION_TOKEN_H

#include <functional>

class OperationToken {
public:
    enum class Type {
        Add,
        Subtract,
        Multiply,
        Divide,
        Exponent,
        LeftParen,
        RightParen
    };

    [[nodiscard]] Type getType() const { return type; }

    [[nodiscard]] char getSymbol() const { return symbol; }

    [[nodiscard]] int getPrecendence() const { return precedence; }

    [[nodiscard]] bool getIsLeftAssociative() const { return isLeftAssociative; }

    [[nodiscard]] std::function<double(double, double)> getFunc() const { return func; }

    static OperationToken getOperationToken(char token);

private:
    Type type;
    char symbol;
    int precedence;
    bool isLeftAssociative;
    std::function<double(double, double)> func;

    OperationToken(const Type type, const char &symbol, const int precedence,
                   const bool isLeftAssociative, const std::function<double(double, double)> &func)
        : type{type}, symbol(symbol), precedence(precedence), isLeftAssociative{isLeftAssociative}, func(func) {
    }
};

#endif //TERMINAL_CALCULATOR_OPERATION_TOKEN_H
