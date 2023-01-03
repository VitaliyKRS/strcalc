/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_EXPRESSION_IEXPRESSIONRESULT_H_
#define STRCALC_EXPRESSION_IEXPRESSIONRESULT_H_

#include "../Common/Value.h"

namespace strcalc {
namespace expression {

template <typename T>
class IExpressionResult {
public:
    virtual ~IExpressionResult() = default;
    virtual common::Value<T> getExpressionResult() const = 0;
};

}  // namespace expression
}  // namespace strcalc

#endif  // STRCALC_EXPRESSION_IEXPRESSIONRESULT_H_
