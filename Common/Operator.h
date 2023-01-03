/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_COMMON_OPERATOR_H_
#define STRCALC_COMMON_OPERATOR_H_

#include <cstdint>

namespace strcalc {
namespace common {

enum class Operator : uint8_t {
    ADDITION = 0,
    SUBSTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENTIAL,
    LEFT_BRACKET,
    RIGHT_BRACKET,
};

bool getOperator(const char& inOperator, common::Operator& outOperator)
{
    bool result{true};
    switch (inOperator) {
    case '+':
        outOperator = Operator::ADDITION;
        break;
    case '-':
        outOperator = Operator::SUBSTRACTION;
        break;
    case '*':
        outOperator = Operator::MULTIPLICATION;
        break;
    case '/':
        outOperator = Operator::DIVISION;
        break;
    case '^':
        outOperator = Operator::EXPONENTIAL;
        break;
    case '(':
        outOperator = Operator::LEFT_BRACKET;
        break;
    case ')':
        outOperator = Operator::RIGHT_BRACKET;
        break;
    default:
        result = false;
        break;
    }

    return result;
}

}  // namespace common
}  // namespace strcalc

#endif  // STRCALC_COMMON_OPERATOR_H_
