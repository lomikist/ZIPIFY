#include <iostream>
#include <queue>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_SIZE 100

struct HuffmanTreeNode
{
	char data;
	int freq;
	HuffmanTreeNode* left;
	HuffmanTreeNode* right;
	HuffmanTreeNode(char character, int frequency)
	{
		data = character;
		freq = frequency;
		left = right = NULL;
	}
};
struct Compare
{
	bool operator()(HuffmanTreeNode* a,
					HuffmanTreeNode* b)
	{
			return a->freq > b->freq;
	}
};
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq)
{
	while (pq.size() != 1) {
		HuffmanTreeNode* left = pq.top();
		pq.pop();
		HuffmanTreeNode* right = pq.top();
		pq.pop();
		HuffmanTreeNode* node = new HuffmanTreeNode('$', left->freq + right->freq);
		node->left = left;
		node->right = right;
		pq.push(node);
	}
	return pq.top();
}
void printCodes(HuffmanTreeNode* root, int arr[], int top)
{
	if (root->left) {
			arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {
			arr[top] = 1;
			printCodes(root->right, arr, top + 1);
	}
	if (!root->left && !root->right) {
		cout << root->data << " ";
		for (int i = 0; i < top; i++) {
				cout << arr[i];
		}
		cout << endl;
	}
}
void HuffmanCodes(char data[], int freq[], int size)
{
	priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> pq;
	
	for (int i = 0; i < size; i++) {
			HuffmanTreeNode* newNode
			= new HuffmanTreeNode(data[i], freq[i]);
		pq.push(newNode);
	}
	HuffmanTreeNode* root = generateTree(pq);
	int arr[MAX_SIZE], top = 0;
	printCodes(root, arr, top);
}

int main() {
    std::ifstream file("image.png");
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

    std::vector<char> characters;
    std::vector<int> frequencies;

    for (const auto& pair : charCount) {
        characters.push_back(pair.first);
        frequencies.push_back(pair.second);
    }

    std::vector<std::pair<char, int>> charFreqPairs;
    for (size_t i = 0; i < characters.size(); ++i) {
        charFreqPairs.emplace_back(characters[i], frequencies[i]);
    }
    std::sort(charFreqPairs.begin(), charFreqPairs.end());
    char data[charFreqPairs.size()];
    int freq[charFreqPairs.size()];
    for (size_t i = 0; i < charFreqPairs.size(); ++i) {
        data[i] = charFreqPairs[i].first;
        freq[i] = charFreqPairs[i].second;
    }
	int size = sizeof(data) / sizeof(data[0]);
	HuffmanCodes(data, freq, size);
	return 0;
}




// int main()
// {
// 	char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
// 	int freq[] = { 5, 9, 12, 13, 16, 45 };
// 	int size = sizeof(data) / sizeof(data[0]);
// 	HuffmanCodes(data, freq, size);
// 	return 0;
// }




