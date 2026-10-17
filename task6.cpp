#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

int path[N][N];

bool solveMaze(int row, int col) {
    if (row >= N || col >= N) {
        return false;
    }

    if (maze[row][col] == 0) {
        return false;
    }

    path[row][col] = 1;

    if (row == N - 1 && col == N - 1) {
        return true;
    }

    if (solveMaze(row, col + 1)) {
        return true;
    }

    if (solveMaze(row + 1, col)) {
        return true;
    }

    path[row][col] = 0;
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            path[i][j] = 0;
        }
    }

    if (solveMaze(0, 0)) {
        cout << "Path found (1 shows the path):" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path exists" << endl;
    }

    return 0;
}
