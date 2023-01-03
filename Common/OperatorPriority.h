/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_COMMON_PRIORITY_H_
#define STRCALC_COMMON_PRIORITY_H_

#include "Operator.h"
#include <cstdint>
#include <map>

namespace strcalc {
namespace common {

enum class OperatorPriority : uint8_t { LOW = 0, MINOR, MAJOR, HIGH };

std::map<Operator, OperatorPriority> priorityMap{
    {Operator::ADDITION, OperatorPriority::LOW},
    {Operator::SUBSTRACTION, OperatorPriority::LOW},
    {Operator::MULTIPLICATION, OperatorPriority::MINOR},
    {Operator::DIVISION, OperatorPriority::MAJOR},
    {Operator::EXPONENTIAL, OperatorPriority::HIGH}};

}  // namespace common
}  // namespace strcalc

#endif  // STRCALC_COMMON_PRIORITY_H_
