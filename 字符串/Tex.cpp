#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '"') {
            cout << ((count % 2 == 0) ? "``": "''");
            count++;
        } else {
            cout << ch;
        }
    }
    return 0;
}