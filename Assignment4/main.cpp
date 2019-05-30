#include <iostream>
#include <array>
#include "dataframe.h"

using namespace std;

int main()
{
    Dataframe d;
    Dataframe::dataframe_t data{29,2,25,13,0};

     d.setData(data,5);
     d.show();

     d.setDataframe(data);
     d.showAll();

     d.checksumIsCorrect();
     d.getDataframe();

     d.clear();
     d.showAll();

    /* Dataframe d1;
      d1.setData(data,5);
      d1.show();
      d1.setDataframe(data);
      d1.show();
      auto check = d1.checksumIsCorrect;
      if(check == true)
      else ...
    */

    return 0;
}
