#include <iostream>
using namespace std;

#define V 4
#define COLORS 3

int graph[V][V] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};

int color[V];

char vertexName[V] = {'A', 'B', 'C', 'D'};
string colorName[COLORS + 1] = {"None", "Red", "Green", "Blue"};

bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool colorGraph(int v) {
    if (v == V) {
        return true;
    }

    for (int c = 1; c <= COLORS; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (colorGraph(v + 1)) {
                return true;
            }

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (colorGraph(0)) {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << vertexName[i] << " : " << colorName[color[i]] << endl;
        }
    } else {
        cout << "No valid coloring exists" << endl;
    }

    return 0;
}
