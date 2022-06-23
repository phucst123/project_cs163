#ifndef TRIE
#define TRIE


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Trie {
    struct TrieNode {
        unordered_map <char, TrieNode*> children;
        bool isEndOfWord;
        string* meaning;


        TrieNode();
        ~TrieNode();

        static void addDef(std::string*& pStr, const std::string def);
    };

    TrieNode* root;


    Trie();
    //~Trie();

    void insert(const std::string& word, const std::string& meaning);

    bool search(const std::string& word);

    string getMeaning(const std::string& word);

    void remove(const std::string& word);

    static bool removeWrapper(Trie::TrieNode* current, const std::string& word, int index);

};


#endif
