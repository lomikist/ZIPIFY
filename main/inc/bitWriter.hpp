#ifndef BIT_BUFFER_HPP
#define BIT_BUFFER_HPP

struct BitWriter
{
public:
    BitWriter(const std::string& out_file_name, const std::unordered_map<char, int>& codes, const std::string& in_file_name);//For zipify
    BitWriter(const std::string& in_file_name);
    // For unzipify
    ~BitWriter();
    void fillRest();
    void add(int bits);
    void addOne(bool bit);
    void nameCodeWrite();
    void nameCodeRead();
    void generateOutputFile();
    void writeDataToOutput(const std::string &data);

    std::string readToStr();
private:
    std::unordered_map<int, char> _codes;
    FileData        _file_data;
    std::fstream    _out_file_z;
    std::fstream    _out_file_uz;
    std::fstream    _in_file_uz;
    unsigned char   _bytes;
    int             _bit_count;
    std::string     _read_result;
};

#endif //BIT_BUFFER_HPP