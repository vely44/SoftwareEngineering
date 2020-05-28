#ifndef MOTORS_H
#define MOTORS_H
#include "device.h"
#include <iostream>

/// The class Motor is_a Device.
/*
class Motor: public Device
{
public:
   Motor(const std::string &id) : Device(id), speed_{0}{}
   virtual ~Motor(){setSpeed(0.0);}
   virtual void initialise() override;
   virtual void reset() override;
   virtual void shutdown() override;
   // C++11 override specifier
   void setSpeed(double speed);
   double getSpeed() const;
private:
   double speed_;
}; */




/// RotationMotor is a Device
class RotationMotor: public Device 
{

public:
    RotationMotor(const std::string &id) : Device(id), RPM_{0}{}
    virtual ~RotationMotor(){setRPM(0.0);}
   virtual void start() override;
   virtual void shutdown() override;
   virtual void restart() override;
   void setRPM(double speed);
   double  getRPM() const;

private:
    double RPM_ = 0;
};


#endif // MOTORS_H