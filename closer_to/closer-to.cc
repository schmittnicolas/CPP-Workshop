#include "closer-to.hh"

CloserTo::CloserTo(int i)
{
    i_ = i;
}

bool CloserTo::operator()(const int& a, const int& b) const
{
    int da = a - i_;
    if (da < 0)
        da = -da;

    int db = b - i_;
    if (db < 0)
        db = -db;

    if (da == db)
        return a < b;
    else
        return da < db;
}