#include "../inc/all_inc.hpp"
#include "bitWriter.hpp"

BitWriter::BitWriter(const std::string& out_file_name, const std::unordered_map<char, int>& codes, const std::string& in_file_name) :
                    _bit_count(0),
                    _bytes(0),
                    _file_data(codes, in_file_name)
{

    _out_file_z.open(out_file_name, std::ios::out | std::ios::binary | std::ios::app);
    if (!_out_file_z.is_open())
        throw std::runtime_error("can't open output file for creating a zip.");
    nameCodeWrite();
}
std::string binaryToString(const std::vector<uint8_t>& data) {
    std::string result;
    for (uint8_t byte : data) {
        std::bitset<8> bits(byte);
        result += bits.to_string();
    }
    return result;
}

BitWriter::BitWriter(const std::string &in_file_name)
{
    _in_file_uz.open(in_file_name, std::ios::in | std::ios::binary);
    if (!_in_file_uz.is_open())
        throw std::runtime_error("can't open output file for creating a zip.");
    nameCodeRead();
    generateOutputFile();
    std::string string_stream = readToStr();
    writeDataToOutput(string_stream);
    // std::cout << a << std::endl;
}

void BitWriter::writeDataToOutput(const std::string & data) 
{
    int tail = 2;
    std::string string_to_write;
    int j = 0;
    for (auto &&i : data)
    {
        std::cout << j++ << " ";
        tail = tail * 10 + (i - 48);
        if(_codes[tail])
        {
            std::cout << _codes[tail];
            _out_file_uz << _codes[tail];        
            tail = 2;
        }
    }
}

void BitWriter::generateOutputFile()
{
    _out_file_uz.open(_file_data._file_name, std::ios::out | std::ios::binary | std::ios::trunc);
    if (!_out_file_uz.is_open())
        throw std::runtime_error("Cant create file from .zipo file.");
}

void BitWriter::nameCodeWrite()
{
    boost::archive::binary_oarchive arcive_output(_out_file_z);
    arcive_output << _file_data;
}

void BitWriter::nameCodeRead()
{
    boost::archive::binary_iarchive archive_input(_in_file_uz);
    archive_input >> _file_data;
    
    for (auto &&i : _file_data._codes)
    {
        _codes[i.second] = i.first;
    }
}

std::string BitWriter::readToStr()
{
    if (!_in_file_uz)
        throw std::runtime_error("Unable to open file");

    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(_in_file_uz)), std::istreambuf_iterator<char>());

    _in_file_uz.close();

    return binaryToString(buffer);
}

BitWriter::~BitWriter()
{
    fillRest();
    _out_file_z.close();
}

void BitWriter::add(int bits)
{
    int num = 0;
    int reversedNum = 2;
    // reverse a number. for reading backward.
    while (bits != 2) {
        int digit = bits % 10;
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

