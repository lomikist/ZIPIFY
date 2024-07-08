#include "../inc/all_inc.hpp"

using std::fstream;
using std::unordered_map;
using std::priority_queue;

// unordered_map<char ,int> readCharFreq(const std::string& name)
// {
//     fstream file;
//     unordered_map<char, int> char_freq;

//     file.open(name, std::ios::in);
//     if (!file)
//         throw(std::runtime_error("can't open the file"));
//     char letter = '\0';
//     while (file.get(letter))
//         char_freq[letter]++;

//     return char_freq;
// }


// using Huffman_queue = priority_queue<node, std::vector<node>, compare>;

// Huffman_queue generateTree(const unordered_map<char, int>& char_freq)
// {
//     Huffman_queue p_queue;
//     for (auto &&i : char_freq)
//         p_queue.push(node(i.second, i.first, nullptr, nullptr));   
//     while (p_queue.size() != 1)
//     {
//         node *left = new node(p_queue.top());
//         p_queue.pop();
//         node *right = new node(p_queue.top());
//         p_queue.pop();
//         node new_node = node(left->_freq + right->_freq, '$', left, right);
//         p_queue.push(new_node);
//     }
//     return p_queue;
// }

// void generateCode(unordered_map<char, std::string>& codes, const node& t_node, int path)
// {
//     if (codes.size())
//     {
//         if(t_node._left)
//             generateCode(codes, *t_node._left, path * 10);
//         else
//             codes[t_node._value] = std::to_string(path).erase(0, 1);
//         if(t_node._right)
//             generateCode(codes, *t_node._right, path * 10 + 1);
//         else
//             codes[t_node._value] = std::to_string(path).erase(0, 1);
//     }else//TODO please check this..... now i think its working but it pretty shit.
//     {
//         if(t_node._left)
//             generateCode(codes, *t_node._left, path * 10);
//         else
//             codes[t_node._value] = std::to_string(path * 10 + 1).erase(0, 1);
//         if(t_node._right)
//             generateCode(codes, *t_node._right, path * 10 + 1);
//         else
//             codes[t_node._value] = std::to_string(path * 10 + 1).erase(0, 1);
//     }
// }

// void createBinaryFile(unordered_map<char, std::string> codes, const std::string& in_file_name, const std::string& out_file_name)
// {
//     FileData file_data(codes, in_file_name);
//     BitWriter data_writer(out_file_name, file_data);

//     fstream in_file;
//     in_file.open(in_file_name, std::ios::in);
//     if (!in_file)
//         throw std::runtime_error("can't open the file.");
    
//     //write file data
//     char letter;
//     while (in_file.get(letter))
//         data_writer.add(codes[letter]);

//     in_file.close();
// }

int main(int argc, char ** argv) {
    try
    {
        if (argc == 1)
        { 
            // Zipify zip("image.png", "out.zipo");
            Zipify zip("test.txt", "out.zipo");
            zip.readCharFreq();
            zip.generateTree();
            zip.generateCode(zip._huff_tree.top(), 2);
            zip.createBinaryFile();
        }
        else {
            Unzipify unzip("out.zipo");
            unzip.readNameData();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

