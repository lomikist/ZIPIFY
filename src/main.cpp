#include "../inc/all_inc.hpp"

bool checkExtenshion(char *file_name, char *extenshion)
{
    int file_len = strlen(file_name);
    int ext_len = strlen(extenshion);
    
    int i = ext_len;
    while (i > 0 && file_name[file_len - i] == extenshion[ext_len - i])
        i--;
    return (i == 0);
}

int main(int argc, char ** argv) {
    try
    {
        if (argc > 1 && !checkExtenshion(argv[1], ".zipo"))
        { 
            Zipify zip(argv[1], "out.zipo");
            zip.readCharFreq();
            zip.generateTree();
            zip.generateCode(zip._huff_tree.top(), 2);
            zip.createBinaryFile();
        }
        else if(argc > 1) {
            Unzipify unzip(argv[1]);
            unzip.readNameData();
        }
        else {
            throw std::runtime_error("please select a file.");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

