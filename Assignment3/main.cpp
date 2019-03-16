#include <array>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    array<int, 3> ar{2,-2,3};
    array<int,3> ar2;

    for(auto& el:ar)
    {
        cout<<el<<" ";
        el*=10;
    }
    cout<<endl;
    int i = 0;
    //ar[0]=10*ar.at(1);
    for(const auto el:ar)
    {
        cout<<el<<" ";
        ar2.at(i) = el;
        i++;
    }
    for(const auto el:ar2)
    {
        cout<<el<<" ";
    }
}