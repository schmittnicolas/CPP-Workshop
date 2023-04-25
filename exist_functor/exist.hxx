#pragma once

#include "exist.hh"

template <class T>
bool Exist<T>::operator()(const T& data)
{
    if (set_.find(data) != set_.end())
        return true;

    set_.insert(data);
    return false;
}