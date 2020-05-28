#ifndef DOFXYRZ_H
#define DOFXYRZ_H

#include <iostream>
#include "cartvec2d.h"

//DOFxyRz Class
class DOFxyRz
{
    //Friend functions - General operatorss
   friend std::ostream& operator<<(std::ostream &os, const DOFxyRz &rhs);
   friend DOFxyRz operator+(const DOFxyRz &lhs, const CartVec2D &rhs);
   friend DOFxyRz operator-(const DOFxyRz &lhs, const CartVec2D &rhs);
   friend DOFxyRz operator+(double x, const DOFxyRz &rhs);
   friend DOFxyRz operator-(double x, const DOFxyRz &rhs);
   friend DOFxyRz operator+(const DOFxyRz &lhs, double x);
   friend DOFxyRz operator-(const DOFxyRz &lhs, double x);

public:
   DOFxyRz(double x, double y): vector_(x ,y), Rz_(0) {}
   DOFxyRz(): vector_(0.0,0.0), Rz_(0) {}
   //Operators +=/-=
   DOFxyRz &operator+=(const DOFxyRz &rhs);
   DOFxyRz &operator+=(const CartVec2D &rhs);
   DOFxyRz &operator+=(double x);
   DOFxyRz &operator-=(const DOFxyRz &rhs);


   //Setters and Getters
   inline double getRz() const{ return Rz_; }
   inline void setRz(double x) { Rz_=x; }
   inline double getX() const{ return vector_.getX(); }
   inline double getY() const{ return vector_.getY(); }

   CartVec2D heading() const;

private:
    //Private values
   CartVec2D vector_;
   double Rz_;
};

#endif // DOFXYRZ_H