#include "Global.h"

void GameWord(Trie*& myTrie)
{
    clearScreen();
    cout << "Rule\n";
    cout << "There will be 1 word and 4 definitions below\nYour mission is to find the correct definition of the given word\n";
    pair<string, string> words[4];
    for (int i = 0; i < 4; i++)
    {
        words[i] = myTrie->getRandomWord();
    }
    vector<int> store;
    int res = rand() % 4;
    cout << "WORD: " << words[res].first << '\n';
    bool visited[4]{ false };
    int option = 1;
    while (store.size() != 4)
    {
        int loop = rand() % 4;
        if (!visited[loop])
        {
            cout << option << " : " << words[loop].second << '\n';
            visited[loop] = true;
            store.push_back(loop);
            option++;
        }
    }
    string congrat[2] = { {"You are great"},{"Well done"} };
    string fail[2] = { {"Not the right one"},{"Oops"} };
    int choice;
    cout << "Answer: ";
    clearInputBuffer();
    cin >> choice;

    int check = rand() % 2;
    if (choice > 4 || choice < 1)
        cout << "Invalid input\n";
    if (store[choice - 1] == res)
    {
        cout << congrat[check] << '\n';
    }
    else
        cout << fail[check] << '\n';
    waitForEnter();
}

void GameDefinition(Trie*& myTrie)
{
    clearScreen();
    cout << "Rule\n";
    cout << "There will be 1 definition and 4 words below\nYour mission is to find the correct word of the given definition\n";
    pair<string, string> words[4];
    for (int i = 0; i < 4; i++)
    {
        words[i] = myTrie->getRandomWord();
    }
    vector<int> store;
    int res = rand() % 4;
    cout << "DEFINITION: " << words[res].second << '\n';
    bool visited[4]{ false };
    int option = 1;
    while (store.size() != 4)
    {
        int loop = rand() % 4;
        if (!visited[loop])
        {
            cout << option << " : " << words[loop].first << '\n';
            visited[loop] = true;
            store.push_back(loop);
            option++;
        }
    }
    string congrat[2] = { {"You are great"},{"Well done"} };
    string fail[2] = { {"Not the right one"},{"Oops"} };
    int choice;
    cout << "Answer: ";
    clearInputBuffer();
    cin >> choice;

    int check = rand() % 2;
    if (choice > 4 || choice < 1)
        cout << "Invalid input\n";
    if (store[choice - 1] == res)
    {
        cout << congrat[check] << '\n';
    }
    else
        cout << fail[check] << '\n';
    waitForEnter();
}