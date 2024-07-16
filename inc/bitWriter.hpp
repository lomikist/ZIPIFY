#ifndef BIT_BUFFER_HPP
#define BIT_BUFFER_HPP

struct BitWriter
{
public:
    BitWriter(  const std::string& out_file_name,
                const Codes& codes,
                const std::string& in_file_name,
                const int last_bit_count  );//For zipify
    ~BitWriter();
    void fillRest();
    void add(long long bits);
    void addOne(bool bit);
    void nameCodeWrite();
private:
    R_codes         _codes;
    FileData        _file_data;
    std::fstream    _out_file_z;
    std::fstream    _out_file_uz;
    std::fstream    _in_file_uz;
    unsigned char   _bytes;
    long             _bit_count;
    std::string     _read_result;
};

#endif //BIT_BUFFER_HPP