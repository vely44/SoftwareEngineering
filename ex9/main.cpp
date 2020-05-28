#include <iostream>
#include <string>
#include "motors.h"
#include "motors.cpp"


int main()
{
   std::string id = "10";
   RotationMotor test(id);
   test.start();
   test.setRPM(22.99);
   std::cout << "ID:" << test.getID() << std::endl;
   std::cout << "Speed:" << test.getRPM() << std::endl;
   test.restart();
   std::cout << "ID:" << test.getID() << std::endl;
   std::cout << "Speed:" << test.getRPM() << std::endl;
   test.shutdown();
   return 0;
}