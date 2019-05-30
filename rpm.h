#include <iostream>


class RotationMotor
{
    public:
    RotationMotor();
    RotationMotor(int RPM);
    int getRPM() const;
    void setRPM(int RPM);
    
    private:
    int RPM_;

}