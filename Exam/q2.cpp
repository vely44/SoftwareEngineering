#include <string>
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>



namespace motion
{

    class Device
    {
        public:
        virtual void selftest() = 0;
        private:
    };

    class CompositeDevice:public Device
    {
        public:
        void selftest();
        void add(Device &dev);
        private:
        std::vector <Device*> devices_;
        
    };
    
    class Motor: public Device
    {
        public:
            Motor(const std::string& ID, int maxRPM):
                ID_(ID), maxRPM_(maxRPM) {++nMotors_;}
            //Motor(const Motor& other) = delete ; 
            ~Motor(){--nMotors_;}
            static int get_nMotors() {return nMotors_;}
            const std::string& get_ID() const {return ID_;}
            int get_maxRPM() const {return maxRPM_;}
            void selftest(){std::cout<<" selftest run "<<ID_<<std::endl;}
        private:
            static int nMotors_;
            std::string ID_;
            const int maxRPM_;

    };
    int Motor::nMotors_=0;



bool findMaxRPM(const motion::Motor& m)
    {
        return m.get_maxRPM() > 150;
    }

void CompositeDevice::add(Device &dev)
{
    devices_.push_back(&dev);

}

void CompositeDevice::selftest() 
{
    for(auto& dev: devices_)
    {
        dev->selftest();
    }
}
}
int main()
{

    motion::Motor m1{"M1",100};
    motion::Motor m2{"M2",1000};
    motion::Motor m3{"M3",200};
    
    std::array<motion::Motor,3> motors{m1,m2,m3};
    //m1 = m2;

    for(const auto& m: motors)
    {
        std::cout<< "ID = "<<m.get_ID()<<std::endl;
    }


    auto motors_iter = std::find_if(begin(motors),end(motors), motion::findMaxRPM);
    std::cout<< motors_iter->get_ID()<<std::endl;
    motion::CompositeDevice mydevices;
    mydevices.add(m1);
    mydevices.add(m2);
    mydevices.add(m1);
    mydevices.selftest();
}