#include <iostream>
using namespace std;
// 也可以使用sort排序,但是排序的复杂度O(n*logn)比n要高
int MoreThanHalfNum_Solution(vector<int> numbers) {
    int n = numbers.size();
    int cur = numbers[0];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (count == 0) {
            cur = numbers[i];
            count++;
        } else if (cur == numbers[i]) {
            count++;
        } else {
            count--;
        }
    }
    int res = cur;
    count = 0;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] == res) count++;
    }
    if (count <= count/2) return 0;
    else return res;
}