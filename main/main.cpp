#include "bitBuffer.hpp"

using std::fstream;
using std::unordered_map;
using std::priority_queue;


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

unordered_map<char ,int> readCharFreq(const std::string& name)
{
    fstream file;
    unordered_map<char, int> char_freq;

    file.open(name, std::ios::in);
    if (!file)
        throw(std::runtime_error("can't open the file"));
    char letter = '\0';
    while (file.get(letter))
        char_freq[letter]++;

    return char_freq;
}


using Huffman_queue = priority_queue<node, std::vector<node>, compare>;

Huffman_queue generateTree(const unordered_map<char, int>& char_freq)
{
    Huffman_queue p_queue;
    for (auto &&i : char_freq)
        p_queue.push(node(i.second, i.first, nullptr, nullptr));   
    while (p_queue.size() != 1)
    {
        node *left = new node(p_queue.top());
        p_queue.pop();
        node *right = new node(p_queue.top());
        p_queue.pop();
        node new_node = node(left->_freq + right->_freq, '$', left, right);
        p_queue.push(new_node);
    }
    return p_queue;
}

void generateCode(unordered_map<char, std::string>& codes, const node& t_node, int path)
{
    if(t_node._left)
        generateCode(codes, *t_node._left, path * 10 + 1);
    else
        codes[t_node._value] = std::to_string(path).erase(0, 1);
    if(t_node._right)
        generateCode(codes, *t_node._right, path * 10);
    else
        codes[t_node._value] = std::to_string(path).erase(0, 1);
}

void createBinaryFile(unordered_map<char, std::string> codes, const std::string& in_file_name, const std::string& out_file_name)
{
    BitBuffer bit_writer(out_file_name);

    fstream in_file;
    in_file.open(in_file_name, std::ios::in);
    if (!in_file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    char letter;
    while (in_file.get(letter))
        bit_writer.add(codes[letter]);

    in_file.close();
}

int main() {
    unordered_map<char, int> char_freq;
    try
    {
        char_freq = readCharFreq("test.txt");

        Huffman_queue huff_tree = generateTree(char_freq);

        unordered_map<char, std::string> codes;

        generateCode(codes, huff_tree.top(), 2);

        createBinaryFile(codes, "test.txt", "out.zipo");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}