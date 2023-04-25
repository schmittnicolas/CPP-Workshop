#pragma once
#include "bimap.hh"

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T1& v1, const T2& v2)
{
    lhs.insert(std::make_pair(v1, v2));
    rhs.insert(std::make_pair(v2, v1));
}

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T2& v1, const T1& v2)
{
    lhs.insert(std::make_pair(v2, v1));
    rhs.insert(std::make_pair(v1, v2));
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T1& v)
{
    auto lhs_it = lhs.find(v);

    if (lhs_it == lhs.end())
        return;

    auto rhs_it = rhs.find(lhs_it->second);
    lhs.erase(lhs_it);
    rhs.erase(rhs_it);
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T2& v)
{
    auto rhs_it = rhs.find(v);
    if (rhs_it == rhs.end())
        return;

    auto lhs_it = lhs.find(rhs_it->second);
    rhs.erase(rhs_it);
    lhs.erase(lhs_it);
}

template <typename T1, typename T2>
typename std::map<T1, T2>::iterator Bimap<T1, T2>::find(const T1& v)
{
    return lhs.find(v);
}

template <typename T1, typename T2>
typename std::map<T2, T1>::iterator Bimap<T1, T2>::find(const T2& v)
{
    return rhs.find(v);
}

template <typename T1, typename T2>
std::size_t Bimap<T1, T2>::size() const
{
    return lhs.size();
}

template <typename T1, typename T2>
void Bimap<T1, T2>::clear()
{
    lhs.clear();
    rhs.clear();
}
