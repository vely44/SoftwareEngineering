#include <iostream>
#include <math.h>

#include "cartvec2d.cpp"
#include "dofxyrz.cpp"




int main()
{
    CartVec2D vec1{1.1, 22.2};
    CartVec2D vec2{33.3, 44.4};
    DOFxyRz DoF1{5.5, 6.6};
    DOFxyRz DoF2{7.7, 88.8};
    std::cout << "_____VALUES______"<<std::endl;
    std::cout << "Vec1:"<< vec1 << std::endl;
    
    std::cout << "Vec2:"<< vec2 << std::endl;
    std::cout << "Dof1:"<< DoF1 << std::endl;
    std::cout << "Dof2:"<< DoF2 << std::endl;
    std::cout << "_________________"<<std::endl;

    std::cout << "_______DoF+Cart________"<<std::endl;
    std::cout << "DoF1 + Vec1: " << DoF1 + vec1 << std::endl;
    std::cout << "DoF2 - Vec2: " << DoF2 - vec2 << std::endl;
    std::cout << "_______DoF+Number__________"<<std::endl;
    std::cout << "DoF2 + 1.11: " << DoF2 + 1.11 << std::endl;
    std::cout << "DoF1 - 2.0: " << DoF1 - 2.0 << std::endl;
    std::cout << "_______Number+DoF__________"<<std::endl;
    std::cout << "4.0 + DoF1: " << 4.0 + DoF1 << std::endl;
    std::cout << "4.0 - DoF2: " << 4.0 - DoF2 << std::endl;
    std::cout << "______DoF2=DoF1+3___________"<<std::endl;
    DoF2 = DoF1 + 3.0;
    std::cout << "DoF2: " << DoF2 << std::endl;
    std::cout << "DoF1 +=: " << DoF1.operator +=(DoF1) << std::endl;
    std::cout << "DoF1 -=: " << DoF1.operator -=(DoF1) << std::endl;
    std::cout << "DoF1 heading: " << DoF1.heading()<< std::endl;

    return 0;
}


