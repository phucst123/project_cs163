#include "Global.h"

using namespace std;

void loadData() {
	//readFromCSV("data\\engtoeng\\", ENGTOENG);
	readFromCSV("data\\engtovie\\", ENGTOVIE);
	//readFromCSV("data\\vietoeng\\", VIETOENG);
	//readFromCSV("data\\slang\\", SLANG);
	//readFromCSV("data\\emoji\\", EMOJI);
}

void saveData() {
	//saveToCSV("data\\engtoeng\\", ENGTOENG);
	saveToCSV("data\\engtovie\\", ENGTOVIE);
	//saveToCSV("data\\vietoeng\\", VIETOENG);
	//saveToCSV("data\\slang\\", SLANG);
	//saveToCSV("data\\emoji\\", EMOJI);
}

void readFromCSV(const std::string& filepath, Trie*& myTrie) {
	string absoluteDir = filepath + "currentdata.txt";
	ifstream fin(absoluteDir);

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

	//waitForEnter();
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
	myTrie->display(fout, true);
	fout.close();
}