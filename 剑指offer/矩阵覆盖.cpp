#include <iostream>
#include <vector>
using namespace std;

// 这道题目也是用的裴波那契数列的递归思想，具体的思路可以进行归纳推理
// 需要使用动态规划来做，而不要直接使用递归，否则时间复杂度太高
int rectCover(int number) {
    vector<int> arr(number, 0);
    if (number == 0) return 0;
    if (number == 1) return 1;
    if (number == 2) return 2;
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < number; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[number - 1];
}

int main() {
    int num;
    cin >> num;
    cout << rectCover(num) << endl;
    return 0;
}