/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_EXPRESSION_IEXPRESSIONHANDLER_H_
#define STRCALC_EXPRESSION_IEXPRESSIONHANDLER_H_

#include "../Common/OperatorPriority.h"
#include "IExpressionListener.h"
#include "IExpressionResult.h"
#include <cmath>
#include <stack>

namespace strcalc {
namespace expression {

template <typename T>
class ExpressionHandler
    : public IExpressionResult<T>
    , public IExpressionListener<T> {
public:
    virtual common::Value<T> getExpressionResult() const override { return mValuesStack.top(); }

    virtual common::Status onValue(const common::Value<T> value) override
    {
        mValuesStack.push(value);
        return common::Status::SUCCESS;
    }
    virtual common::Status onOperator(const common::Operator& op) override
    {
        common::Status status{common::Status::SUCCESS};
        if (mOperatorsStack.empty()) {
            mOperatorsStack.push(op);
        }
        else if (common::priorityMap[mOperatorsStack.top()] <= common::priorityMap[op]) {
            mOperatorsStack.push(op);
        }
        else {
            status = processOperators(op);
        }

        return status;
    }

    virtual common::Status onBracket(const common::Operator& op) override
    {
        common::Status status{common::Status::SUCCESS};
        if (op == common::Operator::LEFT_BRACKET) {
            mOperatorsStack.push(op);
        }
        else {
            status = processOperators(op);
        }

        return status;
    }

    virtual common::Status onFinish() override { return processFinish(); }

private:
    common::Status processOperators(const common::Operator& op)
    {
        common::Status status{common::Status::SUCCESS};
        if (!mOperatorsStack.empty()) {
            if (op == common::Operator::RIGHT_BRACKET) {
                while (mOperatorsStack.top() != common::Operator::LEFT_BRACKET) {
                    status = process();
                    if (status != common::Status::SUCCESS || mOperatorsStack.empty()) {
                        break;
                    }
                }
                mOperatorsStack.pop();
            }
            else {
                do {
                    if (mOperatorsStack.empty()) {
                        break;
                    }

                    if (mOperatorsStack.top() == common::Operator::LEFT_BRACKET ||
                        mOperatorsStack.top() == common::Operator::RIGHT_BRACKET) {
                        break;
                    }

                    if (common::priorityMap[mOperatorsStack.top()] <= common::priorityMap[op]) {
                        break;
                    }

                    status = process();

                    if (status != common::Status::SUCCESS) {
                        break;
                    }

                } while (true);

                mOperatorsStack.push(op);
            }
        }

        return status;
    }

    common::Status processFinish()
    {
        common::Status status{common::Status::SUCCESS};
        while (!mOperatorsStack.empty()) {
            status = process();
            if (status != common::Status::SUCCESS) {
                break;
            }
        }
        return status;
    }

    common::Status process()
    {
        auto rightValue = mValuesStack.top();
        mValuesStack.pop();
        auto leftValue = mValuesStack.top();
        mValuesStack.pop();
        auto prevOp = mOperatorsStack.top();
        mOperatorsStack.pop();

        return calculate(leftValue, rightValue, prevOp);
    }

    common::Status calculate(common::Value<T>& leftValue,
                             common::Value<T>& rightValue,
                             common::Operator op)
    {
        common::Status status{common::Status::SUCCESS};
        common::Value<T> res;
        switch (op) {
        case common::Operator::ADDITION: {
            res = leftValue + rightValue;
            break;
        }
        case common::Operator::SUBSTRACTION: {
            res = leftValue - rightValue;
            break;
        }
        case common::Operator::MULTIPLICATION: {
            res = leftValue * rightValue;
            break;
        }
        case common::Operator::DIVISION: {
            if (rightValue == 0) {
                status = common::Status::DIVIDION_BY_ZERO;
            }
            else {
                res = leftValue / rightValue;
            }
            break;
        }
        case common::Operator::EXPONENTIAL: {
            res = pow(leftValue, rightValue);
            break;
        }
        default:
            status = common::Status::INVALID_OPERATION;
            break;
        }

        if (status == common::Status::SUCCESS) {
            mValuesStack.push(res);
        }

        return status;
    }

private:
    std::stack<common::Value<T>> mValuesStack;
    std::stack<common::Operator> mOperatorsStack;
    common::Value<T> mResultValue;
};

}  // namespace expression
}  // namespace strcalc

#endif  // STRCALC_EXPRESSION_IEXPRESSIONHANDLER_H_
