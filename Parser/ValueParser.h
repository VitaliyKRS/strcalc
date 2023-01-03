/*
 * COPYRIGHT (C) 2023 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_VALUEPARSER_H_
#define STRCALC_PARSER_VALUEPARSER_H_

#include "../Common/Operator.h"
#include "../Expression/IExpressionListener.h"
#include "IParseState.h"
#include "ISymbolParser.h"
#include <string>

namespace strcalc {
namespace parser {

template <typename T>
class ValueParser : public ISymbolParser<T> {
public:
    ValueParser(expression::IExpressionListener<T>& expressionListener,
                ISymbolParser<T>& symbolParser,
                IParseState& parseState)
        : mExpressionListener{expressionListener}
        , mSymbolParser{symbolParser}
        , mParseState{parseState}
    {
    }
    virtual common::Status parseSymbol(std::string::const_iterator& symbol,
                                       const std::string& expr) override
    {
        common::Value<T> val{0};
        common::Status status{common::Status::SUCCESS};
        if (std::isdigit(*symbol)) {
            if (mParseState.getState() == common::State::OPERATOR ||
                mParseState.getState() == common::State::LEFT_BRACKET ||
                mParseState.getState() == common::State::NONE) {
                mParseState.setState(common::State::VALUE);
                while (std::isdigit(*symbol) && symbol != expr.end()) {
                    val = val * 10 + (*symbol - '0');
                    symbol++;
                }

                symbol--;
                status = mExpressionListener.onValue(val);
            }
            else {
                status = common::Status::VALUE_ERROR;
            }
        }
        else {
            status = mSymbolParser.parseSymbol(symbol, expr);
        }
        return status;
    }

private:
    expression::IExpressionListener<T>& mExpressionListener;
    ISymbolParser<T>& mSymbolParser;
    IParseState& mParseState;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_VALUEPARSER_H_
