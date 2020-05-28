#include <iostream>
#include <string>
#include "header.h"

int main()
{
    RotationMotor rotMotor;
    CommandProcessor cmdp;
    cmdp.addCommand("start", std::bind(&RotationMotor::start, &rotMotor));
    cmdp.addCommand("getRPM", std::bind(&RotationMotor::getRPM, &rotMotor));
    cmdp.addCommand("incRPM", std::bind(&RotationMotor::incRPM, &rotMotor));
    cmdp.addCommand("decRPM", std::bind(&RotationMotor::decRPM, &rotMotor));
    cmdp.addCommand("shutdown", std::bind(&RotationMotor::shutdown, &rotMotor));

    cmdp.executeCommand("start");

    cmdp.executeCommand("incRPM");
    cmdp.executeCommand("getRPM");
    cmdp.executeCommand("decRPM");
    cmdp.executeCommand("getRPM");

    cmdp.executeCommand("shutdown");
    
    return 0;

}

//! start() 
/** Description:
 * Display possible commands
 */
void RotationMotor::start ()
{
   
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
   
}



//! shutdown() 
/** Description:
 * Shutdown message + RPM = 0
 */
void RotationMotor::shutdown ()
{
    //Code
    std::cout << "Shutting down..." << std::endl;
    RPM = 0;
   
}




//! restart() 
/** Description:
 * Restart message + RPM = 0
 */
void RotationMotor::restart ()
{
    //Code
    std::cout << "Restarting" << std::endl;
    RPM = 0;
    
}



//! incRPM() 
/** Description:
 * Increase and new value message and...
 * ...RPM adjustment if the max speed is not reached
 */
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




//! decRPM() 
/** Description:
 * Decrease and new value message and...
 * ...RPM adjustment if the min speed is not reached
 */
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



//! getRPM() 
/** Description:
 * Read and display the actual RPM value
 */
void RotationMotor::getRPM ()
{
    std::cout << "RPM:" << RPM << std::endl;
   //return RPM;
}


//! CommandProcessor 
/** Description:
 * Constructor
 */
CommandProcessor::CommandProcessor ():
   commands_{}
{}



//! executeCommand() 
/** Description:
 * Using find() the function is looking for a...
 * ...command(previously made with addCommand()) with the same name...
 * ...with the command
 */
void CommandProcessor::executeCommand(const std::string &command)
{
   //p is iterator
   auto p = commands_.find(command);
   if (p != end(commands_))
   {
      auto commandfunc = (*p).second;
      commandfunc();
   }
   else
   {
      std::cout << "Unknown Command." << std::endl;
   }
}



//! addCommand() 
/** Description:
 * a command is first prepared for certain functions
 */
void CommandProcessor::addCommand(const std::string s, commandfunction_t c)
{
   commands_.insert(std::pair<std::string, commandfunction_t>(s,c));
   commands_[s] = c;
}