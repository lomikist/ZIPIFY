#include "../inc/all_inc.hpp"

FileData::FileData(const std::unordered_map<char, int>& codes, const std::string& file_name)
{
    _file_name = file_name;
    _codes = codes;
}

FileData::FileData(const FileData &other)
{
    this->_codes = other._codes;
    this->_file_name = other._file_name;
}
