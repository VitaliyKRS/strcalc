/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_PARSER_H_
#define STRCALC_PARSER_PARSER_H_

#include "BracketParser.h"
#include "IParser.h"
#include "OperatorParser.h"
#include "ParseState.h"
#include "SymbolParser.h"
#include "ValueParser.h"

namespace strcalc {
namespace parser {

template <typename T>
class Parser : public IParser<T> {
public:
    Parser(expression::IExpressionListener<T>& expressionListener)
        : mParseState{}
        , mOperatorParser{expressionListener, mParseState}
        , mValueParser{expressionListener, mOperatorParser, mParseState}
        , mBracketParser{expressionListener, mValueParser, mParseState}
        , mSymbolParser{expressionListener, mBracketParser, mParseState}
    {
    }
    virtual common::Status parse(const std::string& expr) override
    {
        common::Status status{common::Status::SUCCESS};

        if (!expr.empty()) {
            for (auto it = expr.begin();; it++) {
                status = mSymbolParser.parseSymbol(it, expr);
                if (status != common::Status::SUCCESS || it == expr.end()) {
                    break;
                }
            }
        }
        else {
            status = common::Status::EMPTY_EXPRESSION;
        }
        return status;
    }

private:
    ParseState mParseState;
    OperatorParser<T> mOperatorParser;
    ValueParser<T> mValueParser;
    BracketParser<T> mBracketParser;
    SymbolParser<T> mSymbolParser;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_PARSER_H_
