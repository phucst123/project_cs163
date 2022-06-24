#ifndef MENU
#define MENU

#include "Global.h"

void searchWord(Trie*& myTrie);
void addWord(Trie*& myTrie);
bool deleteWord(Trie*& myTrie);
void viewAllWord(Trie*& myTrie);

void mainMenu();

void detailMenu(Trie*& myTrie);


#endif


