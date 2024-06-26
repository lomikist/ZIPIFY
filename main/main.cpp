#include <iostream>
#include <vector>
#include <fstream>

template <class T>
using vector = std::vector<T>;

using string = std::string;
using std::cout;
using std::cin;
using std::ofstream;

int main(int argc, char ** argv)
{
    int i = 0;
    cout << argv[1];
    ofstream outfile(argv[1], ofstream::binary);
    string text = "hello";
    outfile.write(text.c_str(), text.size());
    outfile.close();
}