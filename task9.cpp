#include <iostream>
using namespace std;

#define N 4

int grid[N][N] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool isSafe(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
        if (grid[i][col] == num) {
            return false;
        }
    }

    int boxRow = row - row % 2;
    int boxCol = col - col % 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[boxRow + i][boxCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (isSafe(row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku()) {
                            return true;
                        }

                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (solveSudoku()) {
        cout << "Solved Sudoku:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
