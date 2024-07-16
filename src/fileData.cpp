#include "../inc/all_inc.hpp"

FileData::FileData(const Codes& codes, const std::string& file_name, const int last_bit_count)
{
    _file_name = file_name;
    _codes = codes;
    _last_byte_bit_count = last_bit_count;
}

FileData::FileData(const FileData &other)
{
    this->_codes = other._codes;
    this->_file_name = other._file_name;
    this->_last_byte_bit_count = other._last_byte_bit_count;
}
