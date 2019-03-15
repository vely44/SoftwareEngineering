#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::array<int, 3> ar{2,-2,3}

    for(auto& el:ar)
    {
        cout<<el<<" ";
        el*=10;
    }
    cout<<endl;
    ar[0]=10*ar[1];
    for(const auto el:ar)
    {
        cout<<el<<"";
    }

}