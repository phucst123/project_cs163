#ifndef GLOBAL
#define GLOBAL

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>

#include "CSV.h"
#include "Trie.h"
#include "Menu.h"
#include "System.h"

using namespace std;

extern Trie* ENGTOENG;
extern Trie* ENGTOVIE;
extern Trie* VIETOENG;
extern Trie* SLANG;
extern Trie* EMOJI;

extern vector<pair<string, string>> FavorListEngToEng;
extern vector<pair<string, string>> FavorListEngToVie;
extern vector<pair<string, string>> FavorListVieToEng;
extern vector<pair<string, string>> FavorListSlang;
extern vector<pair<string, string>> FavorListEmoji;

extern vector<string> HistoryEngToEng;
extern vector<string> HistoryEngToVie;
extern vector<string> HistoryVieToEng;
extern vector<string> HistorySlang;
extern vector<string> HistoryEmoji;



#endif
