#include <iostream>
#include "cartvec2d.h"

//using namespace std;

int main()
{
    CartVec2D vec1{3.0, 1.5};
    CartVec2D vec2{2.3, 2.4};
    std::cout << "vec1:"<< vec1 << std::endl;
    std::cout << "vec2:"<< vec2 << std::endl;
    std::cout << "vec1 + vec2 = "<< vec1 + vec2 << std::endl;
    std::cout << "vec1 - vec2 = "<< vec1 - vec2 << std::endl;
    std::cout << "vec1 * vec2 = "<< vec1 * vec2 << std::endl;
    std::cout << "3.0 * vec2 = "<< 3.0 * vec2 << std::endl;
    std::cout << "vec1 * 4.0 = "<< vec1 * 4.0 << std::endl;
    std::cout << "vec1 += "<< vec1.operator +=(vec1) << std::endl;
    std::cout << "vec1 -= "<< vec1.operator -=(vec1) << std::endl;
    //std::cout << "vec2 - "<< vec2.operator -(vec2) << std::endl;

   return 0;



}

std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs)
{
    os << "[" << rhs.x_ << ", " << rhs.y_ << "]" << "\n";
    return os;
}

CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D solution{lhs};
    return solution += rhs;
}

CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D solution;
    solution.x_ = lhs.x_ - rhs.x_;
    solution.y_ = lhs.y_ - rhs.y_;
    return solution;
}

CartVec2D operator*(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D solution;
    solution.x_ = lhs.x_ * rhs.x_;
    solution.y_ = lhs.y_ * rhs.y_;
    return solution;
}
CartVec2D operator*(double a, const CartVec2D &rhs)
{
    CartVec2D solution;
    solution.x_ = a * rhs.x_;
    solution.y_ = a * rhs.y_;
    return solution;
}

CartVec2D operator*(const CartVec2D &rhs, double a)
{
    CartVec2D solution;
    solution.x_ = a * rhs.x_;
    solution.y_ = a * rhs.y_;
    return solution;
}

CartVec2D &CartVec2D::operator+=(const CartVec2D &rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}

CartVec2D &CartVec2D::operator-=(const CartVec2D &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}