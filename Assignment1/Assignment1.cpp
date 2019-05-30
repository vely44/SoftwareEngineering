#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

int main()
{

    std::cout<<"Start a)\n\n";
    //a)Strings
    // 2 Strings with some text
    std::string mystring_1 = "111111111111111111111";
    std::string mystring_2 = "000000000000000000000";
    //Insert some text
    mystring_1.insert(3,"XXXXXXXX");
    //Remove some text
    mystring_2.erase(2,5);
    //Replace some text
    mystring_2.replace(1,5,"DDDDDDDD");
    std::string mystring_3 = mystring_2 + mystring_1;
    std::string mystring_4 = "AAA";
    std::string mystring_5 = "AAA";
    if(mystring_4.compare(mystring_1)==1)
    {
        std::cout<<"Strings are the same\n";

    }else
    {
        std::cout<<"Strings are not the same\n";
    }
    //Show the strings
    std::cout<<mystring_1<<std::endl;
    std::cout<<mystring_2<<std::endl;
    std::cout<<mystring_3<<std::endl;
    std::cout<<mystring_4<<std::endl;

    
    std::cout<<"Start b)\n\n";
    //b)Vector
    // 4 vectors with some values
    std::vector<int> myvector_1  (10,100);
    std::vector<int> myvector_2  (3,7);
    std::vector<int> myvector_3  (3,8);
    std::vector<int> myvector_4  (3,9);

    //Insert some numbers
    myvector_1.insert(myvector_1.begin(),15);

    //Remove some numbers
    myvector_2.erase(myvector_2.begin(),myvector_2.begin()+3);

    //Replace some numbers
    std::replace(myvector_3.begin(), myvector_3.end(),8,99);



    //Output the vectors with forloop
    std::vector<int>::iterator it;
    for(it=myvector_1.begin();it<myvector_1.end();it++)
    {
        std::cout<< ' ' << *it;
        std::cout<< ' ' << '\n';
    }
    for(it=myvector_2.begin();it<myvector_2.end();it++)
    {
        std::cout<< ' ' << *it;
        std::cout<< ' ' << '\n';
    }
    for(it=myvector_3.begin();it<myvector_3.end();it++)
    {
        std::cout<< ' ' << *it;
        std::cout<< ' ' << '\n';
    }
        for(it=myvector_4.begin();it<myvector_4.end();it++)
    {
        std::cout<< ' ' << *it;
        std::cout<< ' ' << '\n';
    }
    
    std::cout<<"Start c)\n\n";
   //c)Lists
   // 2 lists with some doubles
    std::list<double> mylist_1  (5,99.999);
    std::list<double> mylist_2  (5,6.999);
    std::list<double>::iterator itera;

   //Insert some elements
    itera = mylist_1.begin();
    itera++;
    itera++;
    mylist_1.insert(itera,10);
   //Remove some elements
   mylist_2.remove(7);
   //Replace some elements
    //no replace in list
   //Show the lists
    for(itera=mylist_1.begin();itera!=mylist_1.end();itera++)
    {
        std::cout<< ' ' << *itera;
        std::cout<< ' ' << '\n';
    }
    for(itera=mylist_2.begin();itera!=mylist_2.end();itera++)
    {
        std::cout<< ' ' << *itera;
        std::cout<< ' ' << '\n';
    }


    std::cout<<"Start d)\n\n";
    //Default constructor
    //std::vector<string> vdata1;
    //Initialiser list for init.
    //vector


    return 0;
    
}
