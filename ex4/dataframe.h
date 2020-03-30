#include <array>

class Dataframe
{

public:
    //!default Constructor
    Dataframe();
    //!custom Constructor
    Dataframe(const std::array<uint8_t, 255> &i_Vec1); 

    //!Show Function
    void show() const; 
    void showAll() const;
    //!Checksum Function
    void checksum();
    //!Checksumiscorrect Function
    bool checksumIsCorrect() const;
    //!SetData Function
    void setData(const std::array<uint8_t, 255> &i_Vec2);
    //!clean Function
    void clear();

private:
    const int header = 19;
    int checksum_;
    int size_;
    std::array<uint8_t, 255> data = {{0}};
    void setChecksum();

};