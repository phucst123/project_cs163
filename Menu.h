#ifndef MENU
#define MENU

#include "Global.h"

#define SIZEOFHISTORY 10


void searchWord(Trie*& myTrie, vector<string>& history, vector<string>& favorlist);
void addWord(Trie*& myTrie);
bool deleteWord(Trie*& myTrie);
void viewAllWord(Trie*& myTrie);

void addToHistory(const string &word, vector<string>& history);
void viewHistory(const vector<string>& history);

void addToFavorList(const string& word, vector<string>& favorlist);
void removeFromFavorList(const string& word, vector<string>& favorlist);
void viewFavorList(vector<string>& favorlist);

void addExtraDefinition(string& originaldef);

void mainMenu();

void detailMenu(Trie*& myTrie, vector<string>& history, vector<string>& favorlist);


#endif


