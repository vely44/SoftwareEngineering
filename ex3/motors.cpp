#include <iostream>
#include <array>
#include "header.h"

using namespace std;

void RotationMotor::start (){
   std::string command;
   
   std::cout << "_______________" << std::endl;
   std::cout << "Starting up..." << std::endl;
   std::cout << "Insert Command:" << std::endl;
   std::cout << "shutdown" << std::endl;
   std::cout << "restart" << std::endl;
   std::cout << "incRPM" << std::endl;
   std::cout << "decRPM" << std::endl;
   std::cout << "getRPM" << std::endl;
   std::cout << "_______________" << std::endl;
   std::cout << "Actual Speed:" << std::endl;
   std::cout << "0" << std::endl;
   std::cout << "_______________" << std::endl;

   while (1){
      std::cin >> command;

      if (command == "shutdown"){
         shutdown();
         break;
      }
      else if (command == "restart"){
         restart();
      }
      else if (command == "incRPM"){
         incRPM();
      }
      else if (command == "decRPM"){
         decRPM();
      }
      else if (command == "getRPM"){
         std::cout << "RPM:" << getRPM() << std::endl;
      }
      else{
         std::cout << "Unknown Command" << std::endl;
      }
   }
   
}

void RotationMotor::shutdown ()
{
    //Code
    std::cout << "Shutting down..." << std::endl;
    RPM = 0;
   
}

void RotationMotor::restart ()
{
    //Code
    std::cout << "Restarting" << std::endl;
    RPM = 0;
    
}

void RotationMotor::incRPM ()
{
    //Code
    std::cout << "Increasing RPM" << std::endl;
    RPM += RPMAdjust;
    if (RPM > RPMMax)
    {
        RPM = RPMMax;
    }
    std::cout << "New Value:" << RPM << std::endl;
}

void RotationMotor::decRPM ()
{
    std::cout << "Decreasing RPM" << std::endl;
    RPM -= RPMAdjust;
    if (RPM < RPMMin)
    {
        RPM = RPMMin;
    }
    std::cout << "New Value:" << RPM << std::endl;
    
}

int RotationMotor::getRPM ()
{
   return RPM;
}