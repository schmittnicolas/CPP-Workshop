#pragma once

template <typename T1, typename T2>
class Pair
{
public:
    /// Build the pair (v1, v2)
    Pair(T1 v1, T2 v2)
        : v1_(v1)
        , v2_(v2)
    {}

    /// Returns the first value
    T1& first()
    {
        return v1_;
    }
    const T1& first() const
    {
        return v1_;
    }

    /// Returns the second  value;
    T2& second()
    {
        return v2_;
    }
    const T2& second() const
    {
        return v2_;
    }

    bool operator==(const Pair& other)
    {
        return v1_ == other.first() && v2_ == other.second();
    }

    bool operator!=(const Pair& other)
    {
        return v1_ != other.first() || v2_ != other.second();
    }

private:
    /// The first value
    T1 v1_;
    /// The second value
    T2 v2_;
};
