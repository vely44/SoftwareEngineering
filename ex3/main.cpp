#include <iostream>
#include <array>
#include "motors.cpp"

using namespace std;

int main()
{
        // C++11 STL array template class, parameters between < and >
        // Using C++11 uniform initialisation by an initializer_list {...}
        array <int, 3> ar{2, -2, 3};
        array <int, 3> ar2{0, 0, 0};
        
        // Range-based for loop, el is not the index of a specific
        // element in the array!
        // e1 is a reference to an array element in ar (we used &),
        // now we can change the contents of the array.
        // auto declaration: type will be deduced by the compiler.
        for (auto& el: ar) // b) If & is removed, the *= command is not able to change the values anymore
        {                  // No more refference addresing, but value.
            cout << el << " AR "<<endl;
            el *= 10;//edits can be made here
        }
        cout << endl;

        for (auto& el: ar2) // b) If & is removed, the *= command is not able to change the values anymore
        {                  // No more refference addresing, but value.
            cout << el << " AR2 "<<endl;
        }
        cout << endl;

        std::copy(std::begin(ar),std::end(ar), std::begin(ar2)); // f) copy works with C++ but not with C

        for (auto& el: ar2) // b) If & is removed, the *= command is not able to change the values anymore
        {                  // No more refference addresing, but value.
            cout << el << " AR2 - after copy "<<endl;
        }
        cout << endl;

        ar.at(0) = 10 * ar.at(1);//e) Same effect but .at() command is recommanded due to size checker
        ar[0] = 10 * ar[1];


        for (const auto el: ar)//c) const auto is used to ensure that the values are not changed at this step
        {                      //d) withouth the & el will address by value, this way the elements can only be read 
            cout << el << " AR after edits "<<endl;
            //but not here...
        }
        cout << "End of the basic exercises..."<< endl;
        
        cout << "... ... " << endl;
        cout << " .. .. "<< endl;
        cout << "  . .  "<< endl;
        cout << "   . "<< endl;
        cout << "Running the Motor Driver"<< endl;


   //Array of 4 RotationMotor objects.
   std::array<RotationMotor, 4> map;
   int i=0;//aux counter

   //Use a range based for loop for setting RPM of all motors.
   for ( auto x: map)
   {
      //Increase RPM all 4 motors
      x.incRPM();
      
      std::cout << x.getRPM() << std::endl;
      std::cout << "Motor number "<<i<<" is running"<<std::endl;
      std::cout << std::endl;
      i++;
   }



}
