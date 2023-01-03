/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_OPERATORPARSER_H_
#define STRCALC_PARSER_OPERATORPARSER_H_

#include "../Common/Operator.h"
#include "../Expression/IExpressionListener.h"
#include "IParseState.h"
#include "ISymbolParser.h"
#include <string>

namespace strcalc {
namespace parser {

template <typename T>
class OperatorParser : public ISymbolParser<T> {
public:
    OperatorParser(expression::IExpressionListener<T>& expressionListener, IParseState& parseState)
        : mExpressionListener{expressionListener}
        , mParseState{parseState}
    {
    }
    virtual common::Status parseSymbol(std::string::const_iterator& symbol,
                                       const std::string&) override
    {
        common::Operator op;
        common::Status status{common::Status::SUCCESS};
        if (common::getOperator(*symbol, op)) {
            if (mParseState.getState() == common::State::VALUE ||
                mParseState.getState() == common::State::RIGHT_BRACKET) {
                mParseState.setState(common::State::OPERATOR);
                status = mExpressionListener.onOperator(op);
            }
            else {
                status = common::Status::OPERATOR_ERROR;
            }
        }
        else {
            status = common::Status::INVALID_SYMBOL;
        }
        return status;
    }

private:
    expression::IExpressionListener<T>& mExpressionListener;
    IParseState& mParseState;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_OPERATORPARSER_H_
