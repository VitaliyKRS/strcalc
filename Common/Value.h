/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#ifndef STRCALC_COMMON_VALUE_H_
#define STRCALC_COMMON_VALUE_H_

namespace strcalc {
namespace common {

template <typename T>
class Value {
public:
    Value() = default;
    ~Value() = default;

    Value(T&& value)
        : mValue{std::move(value)} {};
    Value(const Value& obj) { mValue = obj.mValue; }
    Value(Value&& obj)
    {
        mValue = obj.mValue;
        obj.mValue = 0;
    }
    Value& operator=(const Value& obj)
    {
        if (&obj == this)
            return *this;
        mValue = obj.mValue;
        return *this;
    }
    Value& operator=(Value&& obj)
    {
        if (&obj == this)
            return *this;
        mValue = obj.mValue;
        obj.mValue = 0;
        return *this;
    }

    operator T const&() const noexcept { return mValue; }
    operator T&() & noexcept { return mValue; }
    operator T &&() && noexcept { return std::move(mValue); }

private:
    T mValue;
};

}  // namespace common
}  // namespace strcalc

#endif  // STRCALC_COMMON_VALUE_H_
