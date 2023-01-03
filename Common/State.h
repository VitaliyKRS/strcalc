/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_COMMON_STATE_H_
#define STRCALC_COMMON_STATE_H_

#include <cstdint>

namespace strcalc {
namespace common {

enum class State : int8_t {
    NONE = 0,
    VALUE = 1,
    OPERATOR = 2,
    LEFT_BRACKET = 3,
    RIGHT_BRACKET = 4,
};

}  // namespace common
}  // namespace strcalc

#endif  // STRCALC_COMMON_STATUS_H_
