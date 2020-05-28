
#include <map>
#include <functional>



//! RotationMotor class 
/** Description:
 *   Control class for motor
 * Included functions:
 *  void start();
 *   void shutdown();
 *   void restart();
 *   void incRPM();
 *   void decRPM();
 *   void getRPM();
 */
class RotationMotor 
{
   int RPM = 0;
   static const int RPMAdjust = 10;
   static const int RPMMax = 45;
   static const int RPMMin = -45;

public:
   void start();
   void shutdown();
   void restart();
   void incRPM();
   void decRPM();
   void  getRPM();
};



//! CommandProcessor class. 
/** Description:
 * Reads commands in string and then activates the function directly
 */
class CommandProcessor 
{
    
public:
    using commandfunction_t = std::function<void()>;
    CommandProcessor();
    void executeCommand(const std::string &command);
    
    void addCommand(const std::string s, commandfunction_t c);

private:
   std::map<std::string, commandfunction_t> commands_;
};