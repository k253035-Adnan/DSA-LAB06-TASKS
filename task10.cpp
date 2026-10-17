#include <iostream>
using namespace std;

#define ROWS 4
#define COLS 4
#define LEN 3

char grid[ROWS][COLS] = {
    {'B', 'C', 'X', 'D'},
    {'D', 'A', 'T', 'Y'},
    {'X', 'Q', 'Z', 'W'},
    {'M', 'N', 'O', 'P'}
};

char word[LEN + 1] = "CAT";
bool visited[ROWS][COLS];

bool searchWord(int row, int col, int index) {
    if (index == LEN) {
        return true;
    }

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }

    if (visited[row][col] == true || grid[row][col] != word[index]) {
        return false;
    }

    visited[row][col] = true;

    if (searchWord(row, col + 1, index + 1) ||
        searchWord(row, col - 1, index + 1) ||
        searchWord(row + 1, col, index + 1) ||
        searchWord(row - 1, col, index + 1)) {
        return true;
    }

    visited[row][col] = false;
    return false;
}

int main() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }

    bool found = false;

    for (int i = 0; i < ROWS && found == false; i++) {
        for (int j = 0; j < COLS && found == false; j++) {
            if (searchWord(i, j, 0)) {
                found = true;
            }
        }
    }

    if (found) {
        cout << "The word " << word << " exists in the grid" << endl;
    } else {
        cout << "The word " << word << " does not exist in the grid" << endl;
    }

    return 0;
}
