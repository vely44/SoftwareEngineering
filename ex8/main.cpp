#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

#include "cartvec2d.cpp"
#include "dofxyrz.cpp"

using namespace std;

//const double Pi{3.14159265358979323846};
const double PI{3.14159265358979323846};
const double DELTA_t_sec{0.001};
const double MAX_t_sec{10.0};
double velocity{0.2}; // m/sec
double angular_velocity{0.25 * PI}; // rad/sec
double t_sec = 0.0; 


int main()
{
    std::ofstream newfile;
    DOFxyRz roomba;

    //Simulation loop
    while (t_sec <= MAX_t_sec)
    {
        newfile.open ("coords3.csv", std::ios_base::app);
        newfile << t_sec << "," << roomba.getX() << "," << roomba.getY() << "," <<roomba.getRz() << std::endl;
        newfile.close();
        cout << "t = " << t_sec << " " << roomba << endl;
        //Calculate rotation every simulation step
        roomba += angular_velocity * DELTA_t_sec;

        //Calculate translation every simulation step
        CartVec2D delta_heading(roomba.heading() * velocity * DELTA_t_sec);
        roomba += delta_heading;
        t_sec += DELTA_t_sec;
    }




    return 0; 
}

