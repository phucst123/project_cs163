#include "Global.h"

void searchWord(Trie*& myTrie, vector<pair<string, string>>& history, vector<pair<string, string>>& favorlist) {
    string word, result;
    clearInputBuffer();
    cout << "Search: ";
    getline(cin, word);
    if (myTrie->getMeaning(word, result)) {
        addToHistory(word, result, history);

        while (true) {
            clearScreen();
            cout << "MEANING: " << result << endl;
            cout << "1. Add to favorite list" << endl
                << "2. Remove from favorite list" << endl
                << "3. Add your extra definition" << endl
                << "0. Back" << endl;
            int chosen = 0;
            clearInputBuffer();
            cin >> chosen;
            if (chosen == 0)
                break;
            else if (chosen == 1)
                addToFavorList(word, result, favorlist);
            else if (chosen == 2)
                removeFromFavorList(word, favorlist);
            else if (chosen == 3)
                addExtraDefinition(word, result, myTrie);
            else {
                cout << "Invalid choice." << endl;
                milliSleep(1500);
            }

        }
    }
    else {
        cout << result << endl;
        waitForEnter();
    }
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
    myTrie->display(cout, ':');
    waitForEnter();
}

void randomWord(Trie*& myTrie) {
    auto res = myTrie->getRandomWord();
    cout << "Random word: " << res.first << ": " << res.second << endl;
    waitForEnter();
}


void addToHistory(const string& word, const string& def, vector<pair<string, string>>& history) {
    auto it = std::find_if(history.begin(), history.end(),
        [&word](const pair<string, string>& elem) {
            return elem.first == word;
        });

    if (it != history.end())
        history.erase(it);
    history.push_back(make_pair(word, def));
    while (history.size() > SIZEOFHISTORY)
        history.erase(history.begin());
}

void viewHistory(const vector<pair<string, string>>& history) {
    if (history.size() > 0)
        displayList(history);
    else
        cout << "History is empty" << endl;

    waitForEnter();
}


void addToFavorList(const string& word, const string& def, vector<pair<string, string>>& favorlist) {
    auto it = std::find_if(favorlist.begin(), favorlist.end(),
        [&word](const pair<string, string>& elem) {
            return elem.first == word;
        });

    if (it != favorlist.end()) {
        cout << "The word is already in your favorite list" << endl;
        return;
    }
    favorlist.push_back(make_pair(word, def));
}


void removeFromFavorList(const string& word, vector<pair<string, string>>& favorlist) {
    auto it = std::find_if(favorlist.begin(), favorlist.end(),
        [&word](const pair<string, string>& elem) {
            return elem.first == word;
        });

    if (it != favorlist.end()) {
        favorlist.erase(it);
        cout << "The word " << word << " has been removed from your favor list" << endl;
    }
    else {
        cout << "The word " << word << " is not exist in your favor list" << endl;
    }
    waitForEnter();
}


void viewFavorList(const vector<pair<string, string>>& favorlist) {
    if (favorlist.size() > 0)
        displayList(favorlist);
    else
        cout << "Favorite list is empty" << endl;

    waitForEnter();
}

void addExtraDefinition(const string& word, string& result, Trie*& myTrie) {
    auto ptrTrieNode = myTrie->search(word);
    cout << "Type extra definition: ";
    clearInputBuffer();
    string extra;
    getline(cin, extra);
    Trie::TrieNode::addDef(ptrTrieNode->meaning, extra, true);
    result += ";" + extra;
}

void displayList(const vector<pair<string, string>>& myList) {
    for (auto x : myList)
        cout << x.first << ":" << x.second << endl;
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
            detailMenu(ENGTOENG, HistoryEngToEng, FavorListEngToEng);
            break;

        case 2:
            detailMenu(ENGTOVIE, HistoryEngToVie, FavorListEngToVie);
            break;

        case 3:
            detailMenu(VIETOENG, HistoryVieToEng, FavorListVieToEng);
            break;

        case 4:
            detailMenu(SLANG, HistorySlang, FavorListSlang);
            break;

        case 5:
            detailMenu(EMOJI, HistoryEmoji, FavorListEmoji);
            break;

        default:
            cout << "Invalid choice." << endl;
            milliSleep(1500);
            break;
        }
    }
}

void detailMenu(Trie*& myTrie, vector<pair<string, string>>& history, vector<pair<string, string>>& favorlist) {
    while (true) {
        clearScreen();
        cout << "----DASHBOARD----" << endl;
        cout << "1. Search" << endl
            << "2. Add" << endl
            << "3. Delete" << endl
            << "4. View all words" << endl
            << "5. View history search" << endl
            << "6. View favorite list" << endl
            << "7. Get random word" << endl
            << "8. Game section\n"
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
            searchWord(myTrie, history, favorlist);
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

        case 5:
            viewHistory(history);
            break;

        case 6:
            viewFavorList(favorlist);
            break;

        case 7:
            randomWord(myTrie);
            break;
        case 8:
            GameWord(myTrie);
            break;
        case 9:
            Game(myTrie);
            break;
        default:
            cout << "Invalid choice." << endl;
            milliSleep(1500);
            break;
        }
    }
}

void Game(Trie*&myTrie)
{
    while(true)
    {
        clearScreen();
        cout << "----DASHBOARD----" << endl;
        cout << "1. The definition game\n"
             << "2. The word game\n"
             << "3. Return\n";
        int choice;
        clearInputBuffer();
        cin >> choice;
        if (choice == 0 )
            break;
        else{
            switch(choice)
            {
            case 1:
                GameDefinition(myTrie);
                break;
            case 2:
                GameWord(myTrie);
                break;
            default:
                cout << "Invalid choice." << endl;
                milliSleep(1500);
                break;
            }
        }
    }
}