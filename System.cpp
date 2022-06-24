#include "System.h"

using namespace std;

void milliSleep(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
    system("cls");
}

void clearInputBuffer() {
    cin.seekg(0, ios::end);
    cin.clear();
}

void waitForEnter() {
    // https://www.daniweb.com/programming/software-development/threads/90228/flushing-the-input-stream
#pragma push_macro("max")
#undef max
    clearInputBuffer();
    cout << "Press Enter to continue..." << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#pragma pop_macro("max")
}