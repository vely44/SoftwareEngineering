#include <iostream>
#include <dataframe.h>
#include <array>

//using namespace std;

Dataframe :: Dataframe()  //:dataframe
{
   // initialise all data frame elements to 0
    dataframe_.fill(0);
}

void Dataframe :: setData(const Dataframe::dataframe_t &data, std::uint8_t size)
{
    //initialise all data members of the data frame
     int i=0;

    dataframe_[0]=19;
    dataframe_[1]=size;

    while (i<size+1)
    {
        dataframe_[i+2] = data[i];
        i++;
    }

    dataframe_[i+1] = Dataframe::setChecksum();
}

uint8_t Dataframe::setChecksum()
{
    //calculating the checksum and storing the checksum value in the contained data frame
    int x=0;
    std::uint8_t sum=0;

    while(x<static_cast<int>(dataframe_[1]+1))
    {
        sum += dataframe_[x+1];
        x++;
    }

    return ~sum+1;
}

void Dataframe::setDataframe(const Dataframe::dataframe_t &dataframe)
{
    //setter function for the contained data frame
    dataframe_ = dataframe;
}

Dataframe::dataframe_t Dataframe::getDataframe()
{
    //getter function for the contained data frame
    return dataframe_;
}

void Dataframe::show()const
{

    std::cout<<"The contents of the data frame are:"<<std::endl;
    //showing the contents of the data frame
    //static_cast<int>()  //print the data in decimal format

    for (int a=0; a<static_cast<int>(dataframe_[1]+3); a++)
    {
        std::cout<< static_cast<int>(dataframe_[a])<<' ';
    }

    std::cout<<std::endl;
}

void Dataframe::showAll()const
{
     std::cout<<std::endl;
      std::cout<<"All members of the data frame are:"<<std::endl;
    // showing the all members (255) of the contained data frame
    for (auto &x : dataframe_)
    {
        std::cout<< static_cast<int>(x)<<' ';
    }

    std::cout<<std::endl;
}

bool Dataframe::checksumIsCorrect() const
{

    uint8_t sum=0;

    for (int i=1; i<8;i++)
    {
        sum += dataframe_[i];
    }

/*    int x=0;
    x= sum;
    std::cout<<"\n";
    std::cout<<x;
*/

    if ((sum & 0xFF) == 0) //instead of sum
    {
        std::cout<<"The sum is correct."<<std::endl;
        return true;
    }

    else
    {
        std::cout<<"The sum is not correct."<<std::endl;
        return false;
    }

}

void Dataframe::clear()
{
    // clearing the data frame (all 255 data members should become 0)
    for (auto &i : dataframe_)
    {
        i=0;
    }

    std::cout<<"\nThe dataframe has been cleared"<<std::endl;
}
