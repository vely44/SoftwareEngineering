#ifndef CARTVEC2D_H
#define CARTVEC2D_H
#include <iostream>

// CartVec2d represents a 2D Cartesian vector.
class CartVec2D
{
   //Operators
   friend std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs);
   friend CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs);
   friend CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs);
   friend CartVec2D operator*(const CartVec2D &lhs, const CartVec2D &rhs);
   friend CartVec2D operator*(double a, const CartVec2D &rhs);
   friend CartVec2D operator*(const CartVec2D &rhs, double a);

public:
   CartVec2D(double x, double y): x_(x), y_(y) {}
   // Using C++11 constructor delegation for the default constructor.
   CartVec2D(): CartVec2D(0.0, 0.0){}
   // Default copy constructor.
   CartVec2D(const CartVec2D &other) = default;
   // Default assignment operator.
   CartVec2D& operator=(const CartVec2D &other) = default;
   
   // Default destructor.
   ~CartVec2D() = default;

   // += and -= operators are class member functions.
   CartVec2D &operator+=(const CartVec2D &rhs);
   CartVec2D &operator-=(const CartVec2D &rhs);
   // Magnitude of vector.
   //double length() const;

   //Setters and getters
   inline double getX() const{ return x_; }
   inline double getY() const{ return y_; }
   inline void setX(double x) { x_ = x; }
   inline void setY(double y) { y_ = y; }

private:
   //Private coordinates
   double x_;
   double y_;
};

#endif // CARTVEC2D_H