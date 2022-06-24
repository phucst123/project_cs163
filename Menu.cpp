#include "Global.h"

void searchWord(Trie*& myTrie) {
    string word;
    clearInputBuffer();
    cout << "Search: ";
    getline(cin, word);
    string result = myTrie->getMeaning(word);
    cout << result << endl;
    waitForEnter();
}

void addWord(Trie*& myTrie) {
    string word, def;
    clearInputBuffer();
    cout << "New Word: ";
    getline(cin, word);
    clearInputBuffer();
    cout << "Definition: ";
    getline(cin, def);
    myTrie->insert(word, def);
}

bool deleteWord(Trie*& myTrie) {
    string word;
    clearInputBuffer();
    cout << "Word will be deleted: ";
    getline(cin, word);
    if (myTrie->remove(word)) {
        cout << "Deleted" << endl;
        waitForEnter();
        return true;
    }
    else {
        cout << "The word is not exist in dictionary." << endl;
        waitForEnter();
        return false;
    }
}

void viewAllWord(Trie*& myTrie) {
    myTrie->display(cout);
    waitForEnter();
}

void mainMenu() {
    while (true) {
        clearScreen();
        cout << "----DASHBOARD----" << endl;
        cout << "Chose type of dictionary" << endl;
        cout << "1. English to English" << endl
            << "2. English to Vietnamese" << endl
            << "3. Vietnamese to English" << endl
            << "4. Slang words" << endl
            << "5. Emojis" << endl
            << "0. Exit" << endl
            << "----------------" << endl;

        int chosen;
        clearInputBuffer();
        cin >> chosen;
        if (chosen == 0) {
            break;
        }
        switch (chosen)
        {
        case 1:
            detailMenu(ENGTOENG);
            break;

        case 2:
            detailMenu(ENGTOVIE);
            break;

        case 3:
            detailMenu(VIETOENG);
            break;

        case 4:
            detailMenu(SLANG);
            break;

        case 5:
            detailMenu(EMOJI);
            break;

        default:
            cout << "Invalid choice." << endl;
            milliSleep(1500);
            break;
        }
    }
}

void detailMenu(Trie*& myTrie) {
    while (true) {
        clearScreen();
        cout << "----DASHBOARD----" << endl;
        cout << "1. Search" << endl
            << "2. Add" << endl
            << "3. Delete" << endl
            << "4. View all words" << endl
            << "0. Back" << endl
            << "----------------" << endl;

        int chosen;
        clearInputBuffer();
        cin >> chosen;
        if (chosen == 0) {
            break;
        }
        switch (chosen)
        {
        case 1:
            searchWord(myTrie);
            break;

        case 2:
            addWord(myTrie);
            break;

        case 3:
            deleteWord(myTrie);
            break;

        case 4:
            viewAllWord(myTrie);
            break;

        default:
            cout << "Invalid choice." << endl;
            milliSleep(1500);
            break;
        }
    }
}