#ifndef CSV
#define CSV

#include "Global.h"
#include "Trie.h"

#include <fstream>
#include <string>
#include <sstream>


void loadData();

void saveData();

void resetData();

void readFromCSV(const std::string& filepath, Trie*& myTrie);
void readDefFromCSV(const std::string& filepath, Trie*&myTrie);
void saveToCSV(const std::string& filepath, Trie*& myTrie);

void resetFromCSV(const std::string& filepath, Trie*& myTrie);
void readagain(const std::string& filepath, Trie*& myTrie);

void readList(const std::string& filepath, vector<pair<string,string>>& myList);
void saveList(const std::string& filepath, vector<pair<string, string>>& myList);
#endif
