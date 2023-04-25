#pragma once

template <typename T, typename U = T>
concept impl_basic_op = requires(T x, U y)
{
    +x;
    -x;
    +y;
    -y;
    x + y;
    y + x;
    x - y;
    y - x;
    x* y;
    y* x;
    x / y;
    y / x;
};

template <typename T, typename U = T>
concept impl_modulo = requires(T x, U y)
{
    x % y;
    y % x;
};

template <typename T, typename U = T>
concept impl_bitwise_op = requires(T x, U y)
{
    ~x;
    ~y;
    x& y;
    y& x;
    x | y;
    y | x;
    x ^ y;
    y ^ x;
    x << y;
    y << x;
    x >> y;
    y >> x;
};

template <typename T, typename U = T>
concept impl_arith_op =
    (impl_basic_op<T, U> && impl_modulo<T, U> && impl_bitwise_op<T, U>);