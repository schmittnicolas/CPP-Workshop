#pragma once

template <typename Iterator, typename Function>

void my_foreach(Iterator begin, Iterator end, Function function)
{
    for (auto it = begin; it != end; it++)
    {
        function(*it);
    }
}