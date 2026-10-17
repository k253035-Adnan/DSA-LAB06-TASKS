#include <iostream>
using namespace std;

#define SIZE 4

char chars[SIZE] = {'A', 'B', 'C', 'D'};
char result[SIZE];
bool used[SIZE];
int count = 0;

void permute(int pos) {
    if (pos == SIZE) {
        count++;
        for (int i = 0; i < SIZE; i++) {
            cout << result[i];
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        if (used[i] == false) {
            used[i] = true;
            result[pos] = chars[i];

            permute(pos + 1);

            used[i] = false;
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        used[i] = false;
    }

    permute(0);

    cout << "Total permutations: " << count << endl;

    return 0;
}
