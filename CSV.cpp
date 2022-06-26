#include "Global.h"

using namespace std;

void loadData() {
	readFromCSV("data\\engtoeng\\", ENGTOENG);
}

void saveData() {
	saveToCSV("data\\engtoeng\\", ENGTOENG);
}

void readFromCSV(const std::string& filepath, Trie*& myTrie) {
	string absoluteDir = filepath + "currentdata.csv";
	ifstream fin(absoluteDir);

	string line = "";
	while (getline(fin, line)) {
		string word, def;
		stringstream ss(line);
		getline(ss, word, ',');
		getline(ss, def, ',');
		//cout << word << ": " << def << endl;
		line = "";
		myTrie->insert(word, def);
	}

	//waitForEnter();
}

void reset(const std::string& filepath, Trie*& myTrie)
{
	string absoluteDir = filepath + "original.csv";
	ifstream fin(absoluteDir);
	string line = "";
	while(getline(fin,line))
	{
		string word,def;
		stringstream ss(line);
		getline(ss,word,',');
		getline(ss,def,',');
		line  = "";
		myTrie->insert(word,def);
	}
}

void saveToCSV(const std::string& filepath, Trie*& myTrie) {
	string absoluteDir = filepath + "currentdata.csv";
	ofstream fout(absoluteDir);
	myTrie->display(fout, true);
	fout.close();
}