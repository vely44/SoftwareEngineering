//Header file
//RotationMotor Class
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
   int  getRPM();
};



