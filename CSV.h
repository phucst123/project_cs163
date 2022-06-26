#ifndef CSV
#define CSV

#include "Global.h"
#include "Trie.h"

#include <fstream>
#include <string>
#include <sstream>


void loadData();
void saveData();

void readFromCSV(const std::string& filepath, Trie*& myTrie);
void reset(const std::string& filepath, Trie*& myTrie);
void saveToCSV(const std::string& filepath, Trie*& myTrie);



#endif
