#ifndef GLOBAL
#define GLOBAL

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
#include <random>
#include <queue>

#include "CSV.h"
#include "Trie.h"
#include "Menu.h"
#include "System.h"
#include "Game.h"

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

extern vector<pair<string, string>> HistoryEngToEng;
extern vector<pair<string, string>> HistoryEngToVie;
extern vector<pair<string, string>> HistoryVieToEng;
extern vector<pair<string, string>> HistorySlang;
extern vector<pair<string, string>> HistoryEmoji;



#endif
