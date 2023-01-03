/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_SYMBOLPARSER_H_
#define STRCALC_PARSER_SYMBOLPARSER_H_

#include "../Common/Operator.h"
#include "../Expression/IExpressionListener.h"
#include "IParseState.h"
#include "ISymbolParser.h"
#include <string>

namespace strcalc {
namespace parser {

template <typename T>
class SymbolParser : public ISymbolParser<T> {
public:
    SymbolParser(expression::IExpressionListener<T>& expressionListener,
                  ISymbolParser<T>& symbolParser,
                  IParseState& parseState)
        : mExpressionListener{expressionListener}
        , mSymbolParser{symbolParser}
        , mParseState{parseState}
    {
    }
    virtual common::Status parseSymbol(std::string::const_iterator& symbol, const std::string& expr) override
    {
        common::Status status{common::Status::SUCCESS};
        if (symbol != expr.end()) {
            status = mSymbolParser.parseSymbol(symbol, expr);
        } else {
            status = mExpressionListener.onFinish();
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

#endif  // STRCALC_PARSER_SYMBOLPARSER_H_
