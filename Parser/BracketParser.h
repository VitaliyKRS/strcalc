/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_BRACKETPARSER_H_
#define STRCALC_PARSER_BRACKETPARSER_H_

#include "../Common/Operator.h"
#include "../Expression/IExpressionListener.h"
#include "IParseState.h"
#include "ISymbolParser.h"
#include <string>

namespace strcalc {
namespace parser {

template <typename T>
class BracketParser : public ISymbolParser<T> {
public:
    BracketParser(expression::IExpressionListener<T>& expressionListener,
                  ISymbolParser<T>& symbolParser,
                  IParseState& parseState)
        : mExpressionListener{expressionListener}
        , mSymbolParser{symbolParser}
        , mParseState{parseState}
        , mBracketCounter(0)
    {
    }
    virtual common::Status parseSymbol(std::string::const_iterator& symbol,
                                       const std::string& expr) override
    {
        common::Operator op;
        common::Status status{common::Status::SUCCESS};
        if (common::getOperator(*symbol, op)) {
            if (op == common::Operator::LEFT_BRACKET) {
                if (mParseState.getState() == common::State::NONE ||
                    mParseState.getState() == common::State::OPERATOR ||
                    mParseState.getState() == common::State::LEFT_BRACKET) {
                    mBracketCounter++;
                    mParseState.setState(common::State::LEFT_BRACKET);
                    status = mExpressionListener.onBracket(op);
                }
                else {
                    status = common::Status::BRACKET_ERROR;
                }
            }
            else if (op == common::Operator::RIGHT_BRACKET) {
                if ((mParseState.getState() == common::State::VALUE ||
                     mParseState.getState() == common::State::RIGHT_BRACKET) &&
                    mBracketCounter > 0) {
                    mBracketCounter--;
                    mParseState.setState(common::State::RIGHT_BRACKET);
                    status = mExpressionListener.onBracket(op);
                }
                else {
                    status = common::Status::BRACKET_ERROR;
                }
            }
            else {
                status = mSymbolParser.parseSymbol(symbol, expr);
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
    uint8_t mBracketCounter;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_BRACKETPARSER_H_
