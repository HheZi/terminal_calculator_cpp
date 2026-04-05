cmake_minimum_required(VERSION 4.2)
project(terminal_calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(terminal_calculator src/main.cpp
        src/rpn_converter.cpp
        src/include/rpn_converter.h
        src/tokenizer.cpp
        src/include/tokenizer.h
        src/include/operation_token.h
        src/operation_token.cpp
        src/include/number_token.h
        src/rpn_calculator.cpp
        src/include/rpn_calculator.h
)
