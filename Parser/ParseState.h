/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_PARSESTATE_H_
#define STRCALC_PARSER_PARSESTATE_H_

#include "IParseState.h"

namespace strcalc {
namespace parser {

class ParseState : public IParseState {
public:
    ParseState()
        : mCurrentState{common::State::NONE}
    {
    }
    virtual void setState(common::State state) override { mCurrentState = state; }
    virtual common::State getState() const override { return mCurrentState; }

private:
    common::State mCurrentState;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_PARSESTATE_H_
