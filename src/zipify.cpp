#include "../inc/all_inc.hpp"
#include "zipify.hpp"

void Zipify::readCharFreq()
{
    char letter = '\0';
    while (_in_file.get(letter))
        _char_freq[letter]++;
    _in_file.close();
}

void Zipify::generateTree()
{
    for (auto &&i : _char_freq)
        _huff_tree.push(node(i.second, i.first, nullptr, nullptr));   
    while (_huff_tree.size() != 1)
    {
        node *left = new node(_huff_tree.top());
        _huff_tree.pop();
        node *right = new node(_huff_tree.top());
        _huff_tree.pop();
        node new_node = node(left->_freq + right->_freq, '$', left, right);
        _huff_tree.push(new_node);
    }
}

void Zipify::generateCode(const node& t_node, long long path)
{
    if (t_node._left)
        generateCode(*t_node._left, path * 10);
    if (t_node._right)
        generateCode(*t_node._right, path * 10 + 1);    
    if (!t_node._left && !t_node._right)
        _codes[t_node._value] = path;
}

int Zipify::countLastBit()
{
    int count = 0;
    for (auto &&i : _char_freq)
    {
        count += i.second * (std::to_string(_codes[i.first]).size() - 1);
    }
    return count % 8;
}

void Zipify::createBinaryFile()
{
    int last_bit_count = countLastBit();
    BitWriter data_writer(_out_file_name, _codes, _in_file_name, last_bit_count);
    
    _in_file.open(_in_file_name, std::ios::in | std::ios::binary);
    if (!_in_file.is_open())
        throw std::runtime_error("can't open the file for reading 58 line zipify.");
    
    //write file data
    char letter;
    while (_in_file.get(letter))
        data_writer.add(_codes[letter]);

    _in_file.close();
}

Zipify::Zipify(const std::string &in_file_name, const std::string &out_file_name) :
                    _in_file_name(in_file_name),
                    _out_file_name(out_file_name)
{
    _in_file.open(_in_file_name, std::ios::in | std::ios::binary);
    if (!_in_file.is_open())
        throw(std::runtime_error("can't open the file for reading zipify"));
}
Zipify::~Zipify()
{

}
