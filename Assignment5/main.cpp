// C++11 STL pairs and maps

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

// Commands related functions
int start(int data);
int stop(int data);
int repeat(int data);

// Commands related class member functions
class Commands
{
public:
   int update(int data)
   {
      cout << "** exec Commands::update  ** " << data << endl;
      return data;
   }
};

// C++11 instead of typedef, using STL function template
using commandfunction = std::function<int(int)>;

int main()
{

}

int start(int data)
{
   cout << "** exec start ** " << data << endl;
   return data;
}

int stop(int data)
{
   cout << "** exec stop ** " << data << endl;
   return data;
}

int repeat(int data)
{
   cout << "** exec repeat ** " << data << endl;
   return data;
}
