#include <iostream>
#include <math.h>
#include "dofxyrz.h"
#include "cartvec2d.h"

const double Pi = 3.1415926;



std::ostream& operator<<(std::ostream &os, const DOFxyRz &rhs)
{
   os << "(" << rhs.vector_ << "," << rhs.Rz_ << ")";
   return os;
}

DOFxyRz operator+(const DOFxyRz &lhs, const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_ + rhs;
   return result;
}

DOFxyRz operator-(const DOFxyRz &lhs, const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_ - rhs;
   return result;
}

DOFxyRz operator+(double x, const DOFxyRz &rhs)
{
   DOFxyRz result;
   result.vector_ = rhs.vector_;
   result.Rz_ = x + rhs.Rz_;
   while(result.Rz_>Pi)
   {
      result.Rz_ -= 2*Pi;
   }
   
   while(result.Rz_<-Pi)
   {
      result.Rz_ += 2*Pi;
   }
   return result;
}

DOFxyRz operator-(double x, const DOFxyRz &rhs)
{
   DOFxyRz result;
   result.vector_ = rhs.vector_;
   result.Rz_ = x - rhs.Rz_;
   while(result.Rz_>Pi)
   {
      result.Rz_ -= 2*Pi;
   }

   while(result.Rz_<-Pi)
   {
      result.Rz_ += 2*Pi;
   }
   return result;
}

DOFxyRz operator+(const DOFxyRz &lhs, double x)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_;
   result.Rz_ = lhs.Rz_ + x;
   while(result.Rz_>Pi)
   {
      result.Rz_ -= 2*Pi;
   }

   while(result.Rz_<-Pi)
   {
      result.Rz_ += 2*Pi;
   }
   return result;
}

DOFxyRz operator-(const DOFxyRz &lhs, double x)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_;
   result.Rz_ = lhs.Rz_ - x;
   while(result.Rz_>Pi)
   {
      result.Rz_ -= 2*Pi;
   }

   while(result.Rz_<-Pi)
   {
      result.Rz_ += 2*Pi;
   }
   return result;
}

DOFxyRz &DOFxyRz::operator+=(const DOFxyRz &rhs)
{
   vector_ += rhs.vector_;
   return *this;
}

DOFxyRz &DOFxyRz::operator+=(const CartVec2D &rhs)
{
   vector_ += rhs;
   return *this;
}

DOFxyRz &DOFxyRz::operator-=(const DOFxyRz &rhs)
{
   vector_ -= rhs.vector_;
   return *this;
}

CartVec2D DOFxyRz::heading() const
{
   CartVec2D buffer;
   buffer.setX(cos(Rz_));
   buffer.setY(sin(Rz_));
   return buffer;
} 