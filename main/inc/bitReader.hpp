#ifndef BIT_READER_HPP
#define BIT_READER_HPP

#include "all_inc.hpp" 

struct BitReader
{
public:
    BitReader(const std::string& in_file_name);
    // For unzipify
    void nameCodeRead();
    void generateOutputFile();
    void writeDataToOutput(const std::string & data);
    std::string  readToStr();
private:
    std::unordered_map<int, char>   _codes;
    FileData                        _file_data;
    std::fstream                    _out_file_uz;
    std::fstream                    _in_file_uz;
    std::string                     _read_result;
};


#endif /* BIT_READER_HPP */
