
#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
    std::ifstream file("unprintable.txt");
    if (!file) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    std::unordered_map<char, int> charCount;
    char ch;

    while (file.get(ch)) {
        ++charCount[ch];
    }

    file.close();

    for (const auto& pair : charCount) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    return 0;
}