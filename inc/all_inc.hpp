#ifndef ALL_INC_HPP
#define ALL_INC_HPP

#include <string.h>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/string.hpp>

struct node
{
    int _freq;
    char _value;
    node* _left;
    node* _right;
    node(int freq, char value, node* left, node* right) :
        _freq(freq),
        _value(value),
        _left(left),
        _right(right)
    {};
    node(const node& other):
        _freq(other._freq),
        _value(other._value),
        _left(other._left),
        _right(other._right)
    {};
};

struct compare {
    bool operator()(node first, node second)
    {
        if(first._freq > second._freq)
            return true;
        return false;
    }
};



#include <unordered_map>
#include <queue>
#include <exception>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bitset>
#include <sstream>
#include <stdlib.h>     
using Huffman_queue = std::priority_queue<node, std::vector<node>, compare>;

using std::fstream;
using std::unordered_map;
using std::priority_queue;

using Codes = std::unordered_map<char, unsigned long long>;
using R_codes = std::unordered_map<unsigned long long, char>;

#include "fileData.hpp"
#include "bitWriter.hpp"
#include "bitReader.hpp"
#include "zipify.hpp"
#include "unzipify.hpp"

#endif /* ALL_INC_HPP */
