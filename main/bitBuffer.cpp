#include "bitBuffer.hpp"

BitBuffer::BitBuffer(const std::string& file_name) :
                    _bit_count(0),
                    _bytes(0)
{
    _file.open(file_name, std::ios::out | std::ios::binary | std::ios::app);
    if (!_file)
        throw std::runtime_error("can't open file.");
}

BitBuffer::~BitBuffer()
{
    fillRest();
    _file.close();
}

void BitBuffer::add(const std::string& bits)
{
    for (size_t i = 0; i < bits.size(); i++)
    {
        if(bits[i] - '0' == 0 || bits[i] - '0' == 1)
            addOne(bits[i] - '0');
        else 
            throw std::runtime_error("Your trying write number other than 0 and 1.");
    }
}

void BitBuffer::fillRest()
{
    if (_bit_count > 0) {
        _bytes <<= (8 - _bit_count);
        _file.write(reinterpret_cast<char*>(&_bytes), sizeof(_bytes));
        _bytes = 0;
        _bit_count = 0;
    }
}

void BitBuffer::addOne(bool bit)
{
    _bytes <<= 1;
    if (bit) {
        _bytes |= 1;
    }
    _bit_count++;

    if (_bit_count == 8) {
        _file.write(reinterpret_cast<char*>(&_bytes), sizeof(_bytes));
        _bytes = 0;
        _bit_count = 0;
    }
}
