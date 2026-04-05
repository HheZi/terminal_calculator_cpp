#ifndef TERMINAL_CALCULATOR_NUMBER_TOKEN_H
#define TERMINAL_CALCULATOR_NUMBER_TOKEN_H

class NumberToken {
    double value;
public:
    [[nodiscard]] double getValue() const {return value;}

    explicit NumberToken(const double value): value {value} {}
};



#endif //TERMINAL_CALCULATOR_NUMBER_TOKEN_H
