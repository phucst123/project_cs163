#ifndef MENU
#define MENU

#include "Global.h"

#define SIZEOFHISTORY 10


void searchWord(Trie*& myTrie, vector<string>& history);
void addWord(Trie*& myTrie);
bool deleteWord(Trie*& myTrie);
void viewAllWord(Trie*& myTrie);

void addToHistory(const string &word, vector<string>& history);
void viewHistory(const vector<string>& history);

void mainMenu();

void detailMenu(Trie*& myTrie, vector<string>& history);


#endif


