#include <iostream>
using namespace std;

int jumpFloor(int number) {
    if (number == 0) return 1;
    if (number == 1) return 1;
    return jumpFloor(number - 1) + jumpFloor(number - 2); 
}

int main() {
    int num;
    cin >> num;
    cout << jumpFloor(num) << endl;
    return 0;
}