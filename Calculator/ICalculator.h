/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_CALCULATOR_ICALCULATOR_H_
#define STRCALC_CALCULATOR_ICALCULATOR_H_

#include "../Common/Status.h"
#include "../Common/Value.h"
#include <string>

namespace strcalc {
namespace calculator {

template <typename T>
class ICalculator {
public:
    virtual ~ICalculator() = default;
    virtual common::Status calculate(const std::string& line, common::Value<T>& result) = 0;
};

}  // namespace calculator
}  // namespace strcalc

#endif  // STRCALC_CALCULATOR_ICALCULATOR_H_
