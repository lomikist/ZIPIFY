#include "../inc/all_inc.hpp"

BitWriter::BitWriter(   const std::string& out_file_name, 
                        const Codes& codes,
                        const std::string& in_file_name,
                        const int last_bit_count) :
                    _bit_count(0),
                    _bytes(0),
                    _file_data(codes, in_file_name, last_bit_count)
{

    _out_file_z.open(out_file_name, std::ios::out | std::ios::binary | std::ios::app);
    if (!_out_file_z.is_open())
        throw std::runtime_error("can't open output file for creating a zip.");
    nameCodeWrite();
}

void BitWriter::nameCodeWrite()
{
    boost::archive::binary_oarchive arcive_output(_out_file_z);
    arcive_output << _file_data;
}

BitWriter::~BitWriter()
{
    fillRest();
    _out_file_z.close();
}

void BitWriter::add(long long bits)
{
    long long num = 0;
    long long reversedNum = 2;
    // reverse a number. for reading backward.
    while (bits != 2) {
        long long digit = bits % 10;
        reversedNum = reversedNum * 10 + digit;
        bits /= 10;
    }
    //reading backward.
    while (reversedNum != 2)
    {
        num = reversedNum % 10;
        reversedNum /= 10;
        if(num == 0 || num == 1)
            addOne(num);
        else 
            throw std::runtime_error("Your trying write number other than 0 and 1.");
    }
}

void BitWriter::fillRest()
{
    if (_bit_count > 0) {
        _bytes <<= (8 - _bit_count);
        _out_file_z.write(reinterpret_cast<char*>(&_bytes), sizeof(_bytes));
        _bytes = 0;
        _bit_count = 0;
    }
}

void BitWriter::addOne(bool bit)
{
    _bytes <<= 1;
    if (bit) {
        _bytes |= 1;
    }
    _bit_count++;

    if (_bit_count == 8) {
        _out_file_z.write(reinterpret_cast<char*>(&_bytes), sizeof(_bytes));
        _bytes = 0;
        _bit_count = 0;
    }
}

