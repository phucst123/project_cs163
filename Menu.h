#ifndef MENU
#define MENU

#include "Global.h"

#define SIZEOFHISTORY 10


void searchWord(Trie*& myTrie, vector<string>& history, vector<string>& favorlist);
void searchByDef(Trie*& myTrie);
void addWord(Trie*& myTrie);
bool deleteWord(Trie*& myTrie);
void viewAllWord(Trie*& myTrie);
void randomWord(Trie*& myTrie);

void addToHistory(const string& word, const string& def, vector<pair<string, string>>& history);
void viewHistory(const vector<pair<string, string>>& history);

void addToFavorList(const string& word, const string& def, vector<pair<string, string>>& favorlist);
void removeFromFavorList(const string& word, vector<pair<string, string>>& favorlist);
void viewFavorList(const vector<pair<string, string>>& favorlist);

void addExtraDefinition(const string& word, string& result, Trie*& myTrie);

void displayList(const vector<pair<string, string>>& myList);

void mainMenu();

void detailMenu(Trie*& myTrie,Trie*& DefTrie, vector<pair<string, string>>& history, vector<pair<string, string>>& favorlist);

void Game(Trie*& myTrie);
#endif


