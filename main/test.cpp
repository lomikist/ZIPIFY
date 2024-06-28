#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("out.zipo", std::ios::binary);

    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(inputFile)),
                            std::istreambuf_iterator<char>());

    inputFile.close();

    for (char byte : buffer) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }

    return 0;
}
