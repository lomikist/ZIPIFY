
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <exception>
#include <queue>
#include <vector>
#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
#include <bitset>
#include <stdlib.h>     

struct BitBuffer
{
public:
    BitBuffer(const std::string& file_name);
    ~BitBuffer();
    void add(const std::string& bits);
    void fillRest();
    void addOne(bool bit);
private:
    std::fstream    _file;
    unsigned char   _bytes;
    int             _bit_count;
};
