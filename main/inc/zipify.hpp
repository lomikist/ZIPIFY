#ifndef ZIPIFY_HPP
#define ZIPIFY_HPP

struct Zipify
{
public:
    Codes                           _codes;
    std::unordered_map<char, int>   _char_freq;    
    std::fstream                    _in_file;
    std::fstream                    _out_file_z;
    std::string                     _in_file_name;
    std::string                     _out_file_name;
    Huffman_queue                   _huff_tree;//queue with one node
    
public:
    void readCharFreq();
    void generateTree();
    void generateCode(const node& t_node, long long path);
    void createBinaryFile();

    Zipify(const std::string &in_file_name, const std::string &out_file_name);
    ~Zipify();
};


#endif /* ZIPIFY_HPP */
