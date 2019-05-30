#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <utility>

using namespace std;

extern ostream cerr;

static int MAX = 4800;
static int MIN = 0;
static int step = 100;

class RotationMotor
{

    friend std::ostream &operator<<(std::ostream &os, const RotationMotor &rhs);
    public:

    RotationMotor();
    RotationMotor(int RPM);
    int getRPM() const;
    void setRPM(int RPM);
    void decRPM(int RPM);
    void incRPM(int RPM);
    void control();
    private:

    int RPM_;

};

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

void RotationMotor::decRPM(int RPM)
{
   if(RPM>=MAX)
       std::cerr << "To High";
   else if(RPM<=MIN)
    std::cerr << "To Low";
   else {RPM_=RPM;}

}

void RotationMotor::incRPM(int RPM)
{
   if(RPM>=MAX)
       std::cerr << "To High";
   else if(RPM<=MIN)
    std::cerr << "To Low";
   else {RPM_=RPM;}

}
using commandfunction = std::function<int(int)>;

void RotationMotor::control()
{


    
}


int main()
{





        RotationMotor cmds1;
   auto setRPM = std::bind(&RotationMotor::setRPM, &cmds1, placeholders::_1);
       RotationMotor cmds2;
   //auto RotationMotor = std::bind(&RotationMotor::RotationMotor, &cmds2, placeholders::_2);
       RotationMotor cmds3;
   auto incRPM = std::bind(&RotationMotor::incRPM, &cmds3, placeholders::_1);
       RotationMotor cmds4;
   auto decRPM = std::bind(&RotationMotor::decRPM, &cmds4, placeholders::_1);
       RotationMotor cmds5;
   auto getRPM = std::bind(&RotationMotor::getRPM, &cmds5, placeholders::_1);
    
    map<string, commandfunction> cfs{{"start", RotationMotor}, 
    /*{"shutdown", },*/ {"restart", setRPM},
    {"incRPM", incRPM}, {"decRPM", decRPM}, {"getRPM", getRPM}};




    RotationMotor motor_1;
    RotationMotor motor_2;
    cout<<"\nMotor 1\n"<<motor_1<<"\nMotor 2\n"<<motor_2;

    motor_1.setRPM(4900);
    //motor_1.control();
    cout<<"\nMotor 1\n"<<motor_1<<"\nMotor 2\n"<<motor_2;
    motor_2.setRPM(250);
    cout<<"\nMotor 1\n"<<motor_1<<"\nMotor 2\n"<<motor_2;
    cout << "\nEnd Of The Program..." << endl;
    return 0;
}