#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#define SIZE 26

using namespace std;

class TrieNode {
public:
    TrieNode* children[SIZE];
    bool isEndOfWord;
    TrieNode() {
        for(int i = 0; i < SIZE; i++) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode *root, string value) {
    transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
        return tolower(c);
    });

    TrieNode *node = root;
    for(int i = 0; i < value.length(); i++) {
        int index = value[i] - 'a';
        if (!node->children[index]) 
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool search(TrieNode *root, string value) {
    transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
        return tolower(c);
    });

    TrieNode *node = root;
     for(int i = 0; i < value.length(); i++) {
        int index = value[i] - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
     }
     return (node->isEndOfWord);
}

int main() {
    TrieNode *root = new TrieNode;

    string dict[] = {"Python", "C", "JavaScript", "R", "Dart", "Java", "Scala", "SQL"};
    for (auto i : dict) {
        insert(root, i);
    }

    cout << search(root, "Sanket") << endl;
    cout << search(root, "python") << endl;
    cout << search(root, "java") << endl;
    cout << search(root, "javaScript") << endl;

    return 0;
}