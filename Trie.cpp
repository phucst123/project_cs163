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

string Trie::getMeaning(const string& word) {
	if (root == nullptr)
		return "Dictionary is empty";
	TrieNode* current = root;
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i] - 32;
		if (!current->children[index])
			return "There is not that word in dictionary";
		current = current->children[index];
	}

	if (current->isEndOfWord)
		return *(current->meaning);
	else
		return "There is not that word in dictionary";
}



void Trie::remove(const std::string& word) {
	removeWrapper(this->root, word, 0);
}

bool Trie::isEmptyArray(Trie::TrieNode* current) {
	for (int i = 0; i < FULL; ++i) {
		if (current->children[i]) {
			return false;
		}
	}
	return true;
}

Trie::TrieNode* Trie::removeWrapper(Trie::TrieNode* current, const std::string& word, int index) {
	
	if (!current)
		return NULL;

	// If last character of key is being processed
	if (word.length() == index) {

		// This node is no more end of word after removal of given key
		if (current->isEndOfWord)
			current->isEndOfWord = false;

		// If given is not prefix of any other word
		
		if (isEmptyArray(current)) {
			delete (current);
			current = nullptr;
		}

		return current;
	}

	// If not last character, recur for the child
	// obtained using ASCII value
	int i = word[index] - 32;
	current->children[i] = removeWrapper(current->children[i], word, index + 1);

	// If root does not have any child (its only child got deleted), and it is not end of another word.
	if (isEmptyArray(current) && current->isEndOfWord == false) {
		delete (current);
		current = nullptr;
	}
	return current;
	
}

void Trie::display(ostream& out) {
	if (!root)
		return;
	string tmp = "";
	displayWrapper(out, root, tmp);
}

void Trie::displayWrapper(ostream& out, Trie::TrieNode*& node, string tmp) {
	if (node->isEndOfWord)
	{
		cout << tmp << endl;
		tmp = "";
	}

	int i;
	for (i = 0; i < FULL; ++i)
	{
		if (node->children[i])
		{
			char t = i + 32;
			displayWrapper(out, node->children[i], tmp + t);
		}
	}
}