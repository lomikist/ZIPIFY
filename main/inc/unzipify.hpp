#ifndef UNZIPIFY_HPP
#define UNZIPIFY_HPP

struct Unzipify
{
public:
    std::unordered_map<int, char>   _codes; // codes like ("2001" - > "k") "2" is required
    // std::unordered_map<char, int>           _char_freq;    
    std::string                             _in_file_name;
    std::string                             _out_file_name;
    // FileData                                _file_name_data;
    // Huffman_queue                           _huff_tree;//queue with one node

public:
    void readNameData();
    Unzipify(const std::string& infile);
    ~Unzipify();
};

#endif /* UNZIPIFY_HPP */
