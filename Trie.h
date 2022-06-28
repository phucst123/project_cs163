#ifndef TRIE
#define TRIE

#include "Global.h"
#include <iostream>
#include <string>
#include <unordered_map>


#define ONLYLETTER 26
#define FULL 95

using namespace std;

struct Trie {
    struct TrieNode {
        TrieNode* children[FULL];
        bool isEndOfWord;
        string* meaning;


        TrieNode();
        ~TrieNode();

        static void addDef(std::string*& pStr, const std::string, bool exist);
    };

    TrieNode* root;


    Trie();
    //~Trie();

    void insert(const std::string& word, const std::string& meaning);

    bool search(const std::string& word);

    bool getMeaning(const std::string& word, string &result);

    bool remove(const std::string& word);

    static bool isEmptyArray(Trie::TrieNode* current);
    static Trie::TrieNode* removeWrapper(Trie::TrieNode* current, const std::string& word, int index, bool& flag);


    void display(ostream& out, bool comma = false);
    static void displayWrapper(ostream& out, Trie::TrieNode*& node, string tmp, bool comma);
};


#endif
