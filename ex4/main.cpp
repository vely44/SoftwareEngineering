#include <iostream>
#include <array>

#include "dataframe.h"

int main()
{
   std::cout << "Hello World!" << std::endl;
   Dataframe Roomba1;
   Roomba1.show();
   Roomba1.setData({5,29,2,25,13,0,182});
   Roomba1.show();
   if (Roomba1.checksumIsCorrect()== true ){
      std::cout << "Check sum correct" << std::endl;
   }
   Roomba1.clear();
   Roomba1.show();


   return 0;
}


//Functions
Dataframe::Dataframe()
{
   size_ = 0;
   setChecksum();
}

void Dataframe::setChecksum()
{//Add all the data members
   int buffer = 0;
   int i = 0;
   for(i = 0; i <= size_ ; i++)
   {
      buffer += data.at(i);
   }
   checksum_ = buffer;
}

Dataframe::Dataframe(const std::array<uint8_t, 255> &i_Vec1)
{
   int i = 0;
   size_ = sizeof(&i_Vec1) - 1;
   for(i = 0; i <= size_; i++)
   {
      data.at(i) = i_Vec1[i];
   }
   setChecksum();
}

void Dataframe::setData(const std::array<uint8_t, 255> &i_Vec2)
{
   int i = 0;
   size_ = sizeof(&i_Vec2) - 1;
   for(i = 0; i <= size_; i++){
      data.at(i) = i_Vec2[i];
   }
   setChecksum();
}

void Dataframe::show() const 
{
   int i = 0;
   std::cout << "[" << header << "]" << "\t";
   std::cout << "[" << size_ << "]" << "\t";

   if (size_ > 0)
   {
      for(i = 0; i <= (size_ - 1); i++)
      {
         std::cout << "[" << unsigned(data.at(i)) << "]" << "\t";
      }
   }
   
   std::cout << "[" << checksum_ << "]" << "\t";
   std::cout << "\n" ;
}



bool Dataframe::checksumIsCorrect() const
{
   int i = 0;
   int buffer;

   for(i = 0; i <= size_; i++){
      buffer += data[i];
   }
   if(buffer == checksum_){
      return true;
   }
   else{
      return false;
   }
}

void Dataframe::clear()
{
   data = {0};
   size_ = 0;
   checksum_ = 0;

}