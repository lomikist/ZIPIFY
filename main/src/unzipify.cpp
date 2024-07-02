#include "../inc/all_inc.hpp"

Unzipify::Unzipify(const std::string& in_file_name) :
                    _in_file_name(in_file_name)
{
    // _in_file.open(in_file_name, std::ios::in | std::ios::binary);
    // if(!_in_file.is_open())
    //     throw std::runtime_error("cant open file for unzipify.");
}

Unzipify::~Unzipify()
{
    // _in_file.close();
    
}

void Unzipify::readNameData()
{
    BitWriter data_reader(_in_file_name);
}
