#include "Global.h"



using namespace std;


Trie::TrieNode::TrieNode() {
	for (int i = 0; i < FULL; ++i)
		children[i] = nullptr;
	isEndOfWord = false;
	meaning = nullptr;
}

Trie::TrieNode::~TrieNode() {

	delete meaning;
	meaning = nullptr;
}

void Trie::TrieNode::addDef(std::string*& pStr, const std::string def) {
	pStr = new string;
	*pStr = def;
}

Trie::Trie() {
	root = new TrieNode;
}

//Trie::~Trie() {
//
//}

void Trie::insert(const std::string& word, const std::string& definition) {

	TrieNode* current = root;
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i] - 32;
		if (!current->children[index])
			current->children[index] = new TrieNode;
		current = current->children[index];
	}
	current->isEndOfWord = true;
	Trie::TrieNode::addDef(current->meaning, definition);
}


bool Trie::search(const std::string& word) {
	TrieNode* current = root;
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i] - 32;
		if (!current->children[index])
			return false;
		current = current->children[index];
	}
	return current->isEndOfWord;
}

bool Trie::getMeaning(const string& word, string &result) {
	if (root == nullptr) {
		result = "The dictionary is empty.";
		return false;
	}
	TrieNode* current = root;
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i] - 32;
		if (!current->children[index]) {
			result = "Sorry! The word is not exist in this dictionary.";
			return false;
		}
		current = current->children[index];
	}

	if (current->isEndOfWord) {
		result = *(current->meaning);
		return true;
	}
	else {
		result = "There is not that word in dictionary";
		return false;
	}
}



bool Trie::remove(const std::string& word) {
	bool flag = false;
	removeWrapper(this->root, word, 0, flag);
	return flag;
}

bool Trie::isEmptyArray(Trie::TrieNode* current) {
	for (int i = 0; i < FULL; ++i) {
		if (current->children[i]) {
			return false;
		}
	}
	return true;
}

Trie::TrieNode* Trie::removeWrapper(Trie::TrieNode* current, const std::string& word, int index, bool& flag) {

	if (!current)
		return NULL;

	if (word.length() == index) {

		if (current->isEndOfWord) {
			current->isEndOfWord = false;
			flag = true;
		}

		if (isEmptyArray(current)) {
			delete (current);
			current = nullptr;
		}

		return current;
	}

	int i = word[index] - 32;
	current->children[i] = removeWrapper(current->children[i], word, index + 1, flag);

	if (isEmptyArray(current) && current->isEndOfWord == false) {
		delete (current);
		current = nullptr;
	}
	return current;

}

void Trie::display(ostream& out, bool comma) {
	if (!root)
		return;
	string tmp = "";
	//cout << "here" << endl;
	displayWrapper(out, root, tmp, comma);
}

void Trie::displayWrapper(ostream& out, Trie::TrieNode*& node, string tmp, bool comma) {
	if (node->isEndOfWord)
	{
		out << tmp;
		if (comma)
			out << ",";
		else
			out << " : ";
		out << *(node->meaning) << endl;
		tmp = "";
	}

	int i;
	for (i = 0; i < FULL; ++i)
	{
		if (node->children[i])
		{
			char t = i + 32;
			displayWrapper(out, node->children[i], tmp + t, comma);
		}
	}
}