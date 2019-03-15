#include "rpm.h"

#include <iostream>
extern ostream cerr;

using namespace std;

using namespace std;
static int MAX = 4800;
static int MIN = 0;
static int step = 100;

std::ostream &operator<<(std::ostream &os, const RotationMotor &rhs)
{
   os << "[" << rhs.RPM_ << "RPM" << "]";

   return os;
}

RotationMotor::RotationMotor()
   : RotationMotor{1}   // Constructor delegation
{
}

RotationMotor::RotationMotor(int RPM)
   : RPM_{RPM}
{
}

int RotationMotor::getRPM() const
{
    return RPM_;
}

void RotationMotor::setRPM(int RPM)
{
   if(RPM>=MAX)
       std::cerr << "To High";
   else if(RPM<=MIN)
    std::cerr << "To Low";
   else {RPM_=RPM;}

}

void RotationMotor::control()
{
    int com_id;
    typedef enum{
            start=0,
            shutdown=1,
            restart=2,incRPM=3,decRPM=4,getRPM=5
            } commands;
    cout<<"Select function (start, shutdown, restart,incRPM,decRPM,getRPM):";
    cin>>com_id ;

    switch(com_id) {
       case start  :
          RPM_=99;
          break; //optional
       case shutdown  :
          RPM_=0;
          break; //optional
       case restart  :
           RPM_=5;
           break; //optional
        case incRPM  :
        if(RPM_+step>=MAX)
            std::cerr << "To High";
        else if(RPM_+step<=MIN)
         std::cerr << "To Low";
        else {RPM_=RPM_+step;}
           break; //optional
        case decRPM  :
        if(RPM_-step>=MAX)
            std::cerr << "To High";
        else if(RPM_-step<=MIN)
         std::cerr << "To Low";
        else {RPM_=RPM_-step;}
           break; //optional
       // you can have any number of case statements.
       default : //Optional
          RPM_=1;
    }

}
