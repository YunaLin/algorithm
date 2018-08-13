#include <iostream>
using namespace std;

// 注意考虑exponent的各种情况，为0，为负的情况
double Power(double base, int exponent) {
    if (exponent == 0) return 1.0;
    if (exponent == 1) return base;
    if (exponent < 0) {
        exponent *= (-1);
        base = 1/base;
    }
    if (exponent % 2 == 0) {
        return Power(base, exponent / 2)*Power(base, exponent / 2);
    } else {
        return Power(base, exponent - 1) * base;
    }
}

int main() {
    double base;
    int exponent;
    cin >> base >> exponent;
    cout << Power(base, exponent) << endl;
    return 0;
}