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

extern vector<string> FavorListEngToEng;
extern vector<string> FavorListEngToVie;
extern vector<string> FavorListVieToEng;
extern vector<string> FavorListSlang;
extern vector<string> FavorListEmoji;

extern vector<string> HistoryEngToEng;
extern vector<string> HistoryEngToVie;
extern vector<string> HistoryVieToEng;
extern vector<string> HistorySlang;
extern vector<string> HistoryEmoji;



#endif
