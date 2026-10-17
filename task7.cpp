#include <iostream>
using namespace std;

#define SIZE 5
#define TARGET 9

int nums[SIZE] = {2, 3, 5, 6, 8};
int selected[SIZE];

bool findSubset(int index, int sum) {
    if (sum == TARGET) {
        return true;
    }

    if (index == SIZE || sum > TARGET) {
        return false;
    }

    selected[index] = 1;
    if (findSubset(index + 1, sum + nums[index])) {
        return true;
    }

    selected[index] = 0;
    return findSubset(index + 1, sum);
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        selected[i] = 0;
    }

    if (findSubset(0, 0)) {
        cout << "Subset with sum " << TARGET << ": ";
        for (int i = 0; i < SIZE; i++) {
            if (selected[i] == 1) {
                cout << nums[i] << " ";
            }
        }
        cout << endl;
    } else {
        cout << "No subset with sum " << TARGET << " exists" << endl;
    }

    return 0;
}
