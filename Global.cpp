#include "Global.h"

using namespace std;

Trie* ENGTOENG = new Trie;
Trie* ENGTOVIE = new Trie;
Trie* VIETOENG = new Trie;
Trie* SLANG = new Trie;
Trie* EMOJI = new Trie;

vector<string> FavorListEngToEng;
vector<string> FavorListEngToVie;
vector<string> FavorListVieToEng;
vector<string> FavorListSlang;
vector<string> FavorListEmoji;

vector<string> HistoryEngToEng;
vector<string> HistoryEngToVie;
vector<string> HistoryVieToEng;
vector<string> HistorySlang;
vector<string> HistoryEmoji;