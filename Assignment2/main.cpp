#include <iostream>
extern ostream cerr
using namespace std;
static int MAX = 4800;
static int MIN = 0;
static int step = 100;
//Everything here
/////////////////////////////////////////////////////////
//Header file

#include <string>
#include <functional>
#include <map>
#include <utility>

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

//////////////////////////////////////////////////////////////////////
//C++ file


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
    /*
    pair<string, commandfunction> cf{"start", start};
    pair<string, commandfunction> cf{"shutdown", shutdown};
    pair<string, commandfunction> cf{"start", start};
    pair<string, commandfunction> cf{"start", start};
    pair<string, commandfunction> cf{"start", start}; 

    typedef enum{
            start=0,
            shutdown=1,
            restart=2,incRPM=3,decRPM=4,getRPM=5
            } commands;
    cout<<"Select function (start, shutdown, restart,incRPM,decRPM,getRPM):"; */
    
    
    std::map<std::string, commandFunction> cfs{
      {"start", start}, {"shutdown", shutdown}, {"restart", restart},
       {"incRPM", incRPM}, {"decRPM", decRPM}, {"getRPM", getRPM}};

    cin>>com_id ;


    string input;
   const string exitCommand("exit");
   do {
      cout << "\n\tEnter command: ";
      cin >> input;
      if (input != exitCommand) {
         auto iter_command = cfs.find(input);
         if (iter_command != end(cfs)) {
            int dataCommand{0};
            auto fnc = (*iter_command).second;
            cout << "\tInput data (int)? ";
            cin >> dataCommand;
            cout << "\tExecuting function, returned data value = "
                 << fnc(dataCommand) << endl;
         } else {
            cerr << "+++ ERROR unkown command '" << input << "'";
         }
      }
   } while (input != exitCommand);
   cout << endl;


    /*
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
          RPM_=1; */
    }

}


///////////////////////////////////////////////////////////////////////////
//Main file



using namespace std;
using command_function = std::function<int(int)>;

int main()
{

    RotationMotor motor_1;
    RotationMotor motor_2;
    cout<<"\nMotor 1\n"<<motor_1<<"\nMotor 2\n"<<motor_2;

    motor_1.setRPM(4900);
    motor_1.control();
    cout<<"\nMotor 1\n"<<motor_1<<"\nMotor 2\n"<<motor_2;
    motor_2.setRPM(250);
    cout<<"\nMotor 1\n"<<motor_1<<"\nMotor 2\n"<<motor_2;
    cout << "\nEnd Of The Program..." << endl;
    return 0;
}
