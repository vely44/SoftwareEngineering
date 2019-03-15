#ifndef RPM_H
#define RPM_H

#include <iostream>
#include <string>
using namespace std;
class RotationMotor
{

    friend std::ostream &operator<<(std::ostream &os, const RotationMotor &rhs);
    public:

    RotationMotor();
    RotationMotor(int RPM);
    int getRPM() const;
    void setRPM(int RPM);
    void control();
    private:

    int RPM_;

};


#endif // RPM_H
