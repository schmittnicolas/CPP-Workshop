#pragma once

#include "enable-if.hh"
#include "is-numerical.hh"

template <typename T>
T algorithm(T t, typename enable_if<is_numerical<T>::value, T>::type* = 0)
{
    return t;
}