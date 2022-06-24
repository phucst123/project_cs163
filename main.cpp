#include "Global.h"

using namespace std;

int main() {
	//Trie* myTrie = new Trie;
	//
	//myTrie->insert("hi", "xin chao");
	//myTrie->insert("bye", "tam biet");
	///*string c = myTrie->getMeaning("hi");
	//cout << c << endl;

	//myTrie->remove("hi");
	//string t = myTrie->getMeaning("hi");
	//cout << t << endl;
	//cout << "hi" << endl;*/

	//myTrie->remove("go");

	//if (!myTrie->root)
	//	cout << "nullptr" << endl;
	//else
	//	cout << "not null" << endl;

	//string tmp = "";
	//myTrie->display(cout);


	loadData();
	while (true) {
		mainMenu();

		saveData();

		clearScreen();


		cout << "Do you want to quit? (Y/N)" << endl;
		string ch = "";
		while (ch != "y" && ch != "Y" && ch != "n" && ch != "N") {
			getline(cin, ch);
		}
		if (ch == "y" || ch == "Y") {
			break;
		}
	}
}