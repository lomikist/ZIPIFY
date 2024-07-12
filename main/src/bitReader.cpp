#include "../inc/all_inc.hpp"

BitReader::BitReader(const std::string &in_file_name)
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

void BitReader::generateOutputFile()
{
    _out_file_uz.open(_file_data._file_name, std::ios::out | std::ios::binary | std::ios::trunc);
    if (!_out_file_uz.is_open())
        throw std::runtime_error("Cant create file from .zipo file.");
}

void BitReader::nameCodeRead()
{
    boost::archive::binary_iarchive archive_input(_in_file_uz);
    archive_input >> _file_data;
    
    for (auto &&i : _file_data._codes)
    {
        _codes[i.second] = i.first;
    }
}

std::string binaryToString(const std::vector<uint8_t>& data) {
    std::string result;
    for (uint8_t byte : data) {
        std::bitset<8> bits(byte);
        result += bits.to_string();
    }
    return result;
}

std::string BitReader::readToStr()
{
    if (!_in_file_uz)
        throw std::runtime_error("Unable to open file .zipo.");

    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(_in_file_uz)), std::istreambuf_iterator<char>());

    _in_file_uz.close();

    return binaryToString(buffer);
}

void BitReader::writeDataToOutput(const std::string & data) 
{
    long long tail = 2;
    std::string string_to_write;
    long long j = 0;
    for (auto &&i : data)
    {
        tail = tail * 10 + (i - 48);
        if(_codes.find(tail) != _codes.end())
        {
            _out_file_uz << _codes[tail];        
            tail = 2;
        }
    }
}