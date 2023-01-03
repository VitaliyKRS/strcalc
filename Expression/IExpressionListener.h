/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_EXPRESSION_IEXPRESSIONLISTENER_H_
#define STRCALC_EXPRESSION_IEXPRESSIONLISTENER_H_

#include "../Common/Operator.h"
#include "../Common/Status.h"
#include "../Common/Value.h"

namespace strcalc {
namespace expression {
template <typename T>
class IExpressionListener {
public:
    virtual ~IExpressionListener() = default;
    virtual common::Status onValue(const common::Value<T> value) = 0;
    virtual common::Status onOperator(const common::Operator& op) = 0;
    virtual common::Status onBracket(const common::Operator& op) = 0;
    virtual common::Status onFinish() = 0;
};

}  // namespace expression
}  // namespace strcalc

#endif  // STRCALC_EXPRESSION_IEXPRESSIONLISTENER_H_
