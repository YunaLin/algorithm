// 计算两个整数在相加的时候需要多少次进位,上限是9位整数
// int的上限是200000000
#include <iostream>
using namespace std;

int main() {
    int a, b;
    int count = 0;
    while (cin >> a >> b) {
        if (!a && !b) return 0;
        count = 0;
        // 这里使用!a && !b的时候出错了?
        while ((a != 0) && (b != 0)) {
            if (a % 10 + b % 10 > 9) {
                count++;
            }
            a /= 10;
            b /= 10;
        }
        cout << count << endl;
    }
    return 0;
}