#include "Global.h"



using namespace std;


Trie::TrieNode::TrieNode() {
	isEndOfWord = false;
	meaning = nullptr;
}

Trie::TrieNode::~TrieNode() {
	children.clear();
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
		int index = word[i];
		TrieNode* node = current->children[index];
		if (node == nullptr) {
			node = new TrieNode();
			current->children[index] = node;
		}
		current = node;
	}
	current->isEndOfWord = true;
	Trie::TrieNode::addDef(current->meaning, definition);

}


bool Trie::search(const std::string& word) {
	TrieNode* current = root;
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i];
		TrieNode* node = current->children[index];
		if (node == nullptr)
			return false;
		current = node;
	}
	return current->isEndOfWord;
}

string Trie::getMeaning(const string& word) {
	if (root == nullptr)
		return "Dictionary is empty";
	TrieNode* current = root;
	for (int i = 0; i < word.length(); ++i) {
		int index = word[i];
		TrieNode* node = current->children[index];
		if (node == nullptr)
			return "There is not that word in dictionary";
		current = node;
	}
	if (current->isEndOfWord)
		return *(current->meaning);
	else
		return "There is not that word in dictionary";
}



void Trie::remove(const std::string& word) {
	removeWrapper(this->root, word, 0);
}

bool Trie::removeWrapper(Trie::TrieNode* current, const std::string& word, int index) {
	if (index == word.length()) {
		if (!current->isEndOfWord) {
			return false;
		}
		current->isEndOfWord = false;

		// just delete the meaning pointer where it contains link to string definition
		delete current->meaning;
		current->meaning = nullptr;
		// if current has no other mapping then return true

		return current->children.size() == 0;
	}
	char ch = word[index];
	Trie::TrieNode* node = current->children[ch];
	if (node == nullptr) {
		return false;
	}
	bool shouldDeleteCurrentNode = removeWrapper(node, word, index + 1);
	// if true is returned then delete the mapping of character and trienode reference from map.
	if (shouldDeleteCurrentNode) {
		current->children.erase(ch);
		// return true if no mappings are left in the map.
		if (current->children.size() == 0) {
			delete current; // deallocate
			current = nullptr;
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}