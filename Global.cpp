#include "Global.h"

using namespace std;

Trie* ENGTOENG = new Trie;
Trie* ENGTOVIE = new Trie;
Trie* VIETOENG = new Trie;
Trie* SLANG = new Trie;
Trie* EMOJI = new Trie;

vector<pair<string, string>> FavorListEngToEng;
vector<pair<string, string>> FavorListEngToVie;
vector<pair<string, string>> FavorListVieToEng;
vector<pair<string, string>> FavorListSlang;
vector<pair<string, string>> FavorListEmoji;

vector<pair<string, string>> HistoryEngToEng;
vector<pair<string, string>> HistoryEngToVie;
vector<pair<string, string>> HistoryVieToEng;
vector<pair<string, string>> HistorySlang;
vector<pair<string, string>> HistoryEmoji;