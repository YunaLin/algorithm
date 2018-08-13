#include <iostream>
#include <math.h>
using namespace std;
#define BITS_NUM 64

// 因为要考虑负数的情况，所以每次将n和temp比较后可以从右往左判断那一位是不是1，
// 判断完以后将temp左移一位，不断地往左判断，因为int最大是64位，所以就设定了循环64次。
int  NumberOf1(int n) {
    int temp = 1;
    int count = 0;
    int res = 0;
    while (count < BITS_NUM) {
        if ((temp & n) != 0) {
            res++;
        }
        temp <<= 1;
        count++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << NumberOf1(n) <<endl;
    return 0;
}
