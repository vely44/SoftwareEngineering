#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <array>
#include <iostream>


class Dataframe {

public:
    //dataframe type
    using dataframe_t = std::array<uint8_t, 255>;

    Dataframe(); //default constructor

    //member functions
    void setData(const Dataframe::dataframe_t &in_data, std::uint8_t in_size);
    uint8_t setChecksum();
    void setDataframe(const Dataframe::dataframe_t &dataframe);
    dataframe_t getDataframe();
    void show()const;
    void showAll()const;
    bool checksumIsCorrect() const;
    void clear();

private:

    dataframe_t dataframe_;

};

#endif // DATAFRAME_H
