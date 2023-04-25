#include "vector.hh"

Vector& Vector::operator+=(const Vector& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector& Vector::operator*=(int scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    os << "{" << vect.x << "," << vect.y << "}";
    return os;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    Vector vect(lhs.x + rhs.x, lhs.y + rhs.y);
    return vect;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    Vector vect(lhs.x - rhs.x, lhs.y - rhs.y);
    return vect;
}

Vector operator*(const Vector& lhs, int scalar)
{
    Vector vect(lhs.x * scalar, lhs.y * scalar);
    return vect;
}

Vector operator*(int scalar, const Vector& rhs)
{
    Vector vect(rhs.x * scalar, rhs.y * scalar);
    return vect;
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    return rhs.x * lhs.x + rhs.y * lhs.y;
}