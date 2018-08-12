#include <iostream>
using namespace std;

// 根据规律推导即可，对于最后一步，可以走1级，2级，3级，。。。n级
// 所以是f1 + f2 + f3 +...f(n-1)+1
int jumpFloorII(int number) {
    if (number == 1) return 1;
    if (number == 0) return 1;
    return jumpFloorII(number - 1) * 2;
}

int main() {
    int num;
    cin >> num;
    cout << jumpFloorII(num) << endl;
    return 0;
}