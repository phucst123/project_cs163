#include "Global.h"

using namespace std;

void loadData() {
	//readFromCSV("data\\engtoeng\\", ENGTOENG);
	readFromCSV("data\\engtovie\\", ENGTOVIE);
	//readFromCSV("data\\vietoeng\\", VIETOENG);
	//readFromCSV("data\\slang\\", SLANG);
	//readFromCSV("data\\emoji\\", EMOJI);

	readList("data\\engtoeng\\", FavorListEngToEng);
	readList("data\\engtovie\\", FavorListEngToVie);
	readList("data\\vietoeng\\", FavorListVieToEng);
	readList("data\\slang\\", FavorListSlang);
	readList("data\\emoji\\", FavorListEmoji);

}

void saveData() {
	//saveToCSV("data\\engtoeng\\", ENGTOENG);
	saveToCSV("data\\engtovie\\", ENGTOVIE);
	//saveToCSV("data\\vietoeng\\", VIETOENG);
	//saveToCSV("data\\slang\\", SLANG);
	//saveToCSV("data\\emoji\\", EMOJI);

	saveList("data\\engtoeng\\", FavorListEngToEng);
	saveList("data\\engtovie\\", FavorListEngToVie);
	saveList("data\\vietoeng\\", FavorListVieToEng);
	saveList("data\\slang\\", FavorListSlang);
	saveList("data\\emoji\\", FavorListEmoji);
}

void readFromCSV(const std::string& filepath, Trie*& myTrie) {
	string absoluteDir = filepath + "currentdata.txt";
	ifstream fin(absoluteDir);
	if (!fin.is_open())
		cout << "CANNOT OPEN FILE " << absoluteDir << endl;
	else {
		string line = "";
		while (getline(fin, line)) {
			string word, def;
			stringstream ss(line);
			getline(ss, word, ':');
			getline(ss, def, '\n');
			//cout << word << ": " << def << endl;
			line = "";
			myTrie->insert(word, def);
		}
	}
}

//
//void reset(const std::string& filepath, Trie*& myTrie)
//{
//	string absoluteDir = filepath + "originaldata.txt";
//	ifstream fin(absoluteDir);
//	string line = "";
//	while(getline(fin,line))
//	{
//		string word,def;
//		stringstream ss(line);
//		getline(ss,word,',');
//		getline(ss,def,',');
//		line  = "";
//		myTrie->insert(word,def);
//	}
//}

void saveToCSV(const std::string& filepath, Trie*& myTrie) {
	string absoluteDir = filepath + "currentdata.txt";
	ofstream fout(absoluteDir);
	myTrie->display(fout);
	fout.close();
}


void readList(const std::string& filepath, vector<pair<string, string>>& myList) {
	string absoluteDir = filepath + "favor.txt";
	ifstream fin(absoluteDir);
	if (!fin.is_open())
		cout << "CANNOT OPEN FILE " << absoluteDir << endl;
	else {
		string line = "";
		while (getline(fin, line)) {
			string word, def;
			stringstream ss(line);
			getline(ss, word, ':');
			getline(ss, def, '\n');
			//cout << word << ": " << def << endl;
			line = "";
			myList.push_back(make_pair(word, def));
		}
		fin.close();
	}
}

void saveList(const std::string& filepath, vector<pair<string, string>>& myList) {
	string absoluteDir = filepath + "favor.txt";
	ofstream fout(absoluteDir);
	for (auto x : myList)
		fout << x.first << ":" << x.second << endl;
	fout.close();
}