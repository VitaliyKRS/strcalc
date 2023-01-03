/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_CALCULATOR_CALCULATOR_H_
#define STRCALC_CALCULATOR_CALCULATOR_H_

#include "ICalculator.h"

#include "../Expression/ExpressionHandler.h"
#include "../Parser/Parser.h"

namespace strcalc {
namespace calculator {

template <typename T>
class Calculator : public ICalculator<T> {
public:
    Calculator()
        : mExpressionHadler{}
        , mParser{mExpressionHadler}
    {
    }
    virtual common::Status calculate(const std::string& line, common::Value<T>& result) override
    {
        common::Status status{common::Status::SUCCESS};
        status = mParser.parse(line);
        if (status == common::Status::SUCCESS) {
            result = mExpressionHadler.getExpressionResult();
        }
        return status;
    }

private:
    expression::ExpressionHandler<T> mExpressionHadler;
    parser::Parser<T> mParser;
};

}  // namespace calculator
}  // namespace strcalc

#endif  // STRCALC_CALCULATOR_CALCULATOR_H_
