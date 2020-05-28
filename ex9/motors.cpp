#include <iostream>
#include <array>
#include "motors.h"



void RotationMotor::start ()
{
   
   std::cout << "_______________" << std::endl;
   std::cout << "Starting up..." << std::endl;
    RPM_=0;
   
}

void RotationMotor::shutdown ()
{
    //Code
    std::cout << "Shutting down..." << std::endl;
    RPM_ = 0;
   
}

void RotationMotor::restart ()
{
    //Code
    std::cout << "Restarting" << std::endl;
    RPM_ = 0;
    
}

void RotationMotor::setRPM (double RPM)
{
    //Code
   RPM_=RPM;
}


double RotationMotor::getRPM ()const
{
   return RPM_;
}