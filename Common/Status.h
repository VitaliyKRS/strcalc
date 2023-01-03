/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_COMMON_STATUS_H_
#define STRCALC_COMMON_STATUS_H_

#include <cstdint>

namespace strcalc {
namespace common {

enum class Status : int8_t {
    SUCCESS = 0,
    INVALID_SYMBOL = -1,
    OPERATOR_ERROR = -2,
    BRACKET_ERROR = -3,
    VALUE_ERROR = -4,
    EMPTY_EXPRESSION = -5,
    DIVIDION_BY_ZERO = -6,
    INVALID_OPERATION = -7
};

}  // namespace common
}  // namespace strcalc

#endif  // STRCALC_COMMON_STATUS_H_
