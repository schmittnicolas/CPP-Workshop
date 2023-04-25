#include "forward-multiplication.hh"

lambda_type create_lambda()
{
    return [](int x) { return [x](int y) { return x * y; }; };
}