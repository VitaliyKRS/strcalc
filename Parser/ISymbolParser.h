/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_ISYMBOLPARSER_H_
#define STRCALC_PARSER_ISYMBOLPARSER_H_

#include "../Common/Status.h"
#include <string>

namespace strcalc {
namespace parser {

template <typename T>
class ISymbolParser {
public:
    virtual ~ISymbolParser() = default;
    virtual common::Status parseSymbol(std::string::const_iterator& symbol, const std::string& str) = 0;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_ISYMBOLPARSER_H_
