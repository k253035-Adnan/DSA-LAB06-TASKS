#include <iostream>
using namespace std;

void printReverse(char s[], int i) {
    if (s[i] == '\0') {
        return;
    }
    printReverse(s, i + 1);
    cout << s[i];
}

int main() {
    char s[100];
    cout << "Enter a string: ";
    cin >> s;

    cout << "Reversed: ";
    printReverse(s, 0);
    cout << endl;

    return 0;
}
