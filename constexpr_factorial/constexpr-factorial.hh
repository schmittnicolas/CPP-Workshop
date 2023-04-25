#pragma once

constexpr unsigned long long factorial(unsigned int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}