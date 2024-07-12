#ifndef FILE_DATA_HPP
#define FILE_DATA_HPP

struct FileData
{
    Codes       _codes; // codes like ("k" - > "2001") 2 is required
    std::string _file_name;
    int         _last_byte_bit_count;
    
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & _last_byte_bit_count;
        ar & _file_name;
        ar & _codes;
    }
    
    FileData(const Codes& codes, const std::string& file_name);
    FileData(const FileData& other);
    FileData(){};
};

#endif