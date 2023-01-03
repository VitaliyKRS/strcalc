/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_IPARSESTATE_H_
#define STRCALC_PARSER_IPARSESTATE_H_

#include "../Common/State.h"

namespace strcalc {
namespace parser {

class IParseState {
public:
    virtual ~IParseState() = default;
    virtual void setState(common::State state) = 0;
    virtual common::State getState() const = 0;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_IPARSESTATE_H_
