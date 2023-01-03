/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_PARSER_IPARSER_H_
#define STRCALC_PARSER_IPARSER_H_

#include "../Common/Status.h"
#include <string>

namespace strcalc {
namespace parser {

template <typename T>
class IParser {
public:
    virtual ~IParser() = default;
    virtual common::Status parse(const std::string& line) = 0;
};

}  // namespace parser
}  // namespace strcalc

#endif  // STRCALC_PARSER_IPARSER_H_
