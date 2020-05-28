#include <iostream>
#include "cartvec2d.h"
//Operator <<
std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs)
{
    os << "[" << rhs.x_ << ", " << rhs.y_ << "]" << "\n";
    return os;
}
//Operator +
CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D result{lhs};
    return result += rhs;
}
//Operator -
CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D result;
    result.x_ = lhs.x_ - rhs.x_;
    result.y_ = lhs.y_ - rhs.y_;
    return result;
}
//Operator * (Cartvec*Cartvec)
CartVec2D operator*(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D result;
    result.x_ = lhs.x_ * rhs.x_;
    result.y_ = lhs.y_ * rhs.y_;
    return result;
}
//Operator * (a*Cartvec)
CartVec2D operator*(double a, const CartVec2D &rhs)
{
    CartVec2D result;
    result.x_ = a * rhs.x_;
    result.y_ = a * rhs.y_;
    return result;
}
//Operator * (Cartvec * a)
CartVec2D operator*(const CartVec2D &rhs, double a)
{
    CartVec2D result;
    result.x_ = a * rhs.x_;
    result.y_ = a * rhs.y_;
    return result;
}
//Operator +=
CartVec2D &CartVec2D::operator+=(const CartVec2D &rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}
//Operator-=
CartVec2D &CartVec2D::operator-=(const CartVec2D &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}