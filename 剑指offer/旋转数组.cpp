#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
    int len = rotateArray.size();
    if (len <= 0) return 0;
    int mid = 0, min = 0, max = len - 1, res = INT_MAX;
    // 注意最后两个数字的比较，需要独立出来进行处理
    while (min < max - 1) {
        mid = (min + max)/2;
        if (rotateArray[mid] <= rotateArray[max]) {
            max = mid;
        } else {
            min = mid;
        }
    }
    return (rotateArray[min] < rotateArray[max]) ? rotateArray[min] : rotateArray[max];
}

int main() {
    vector<int> data;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        data.push_back(num);
    }
    cout << minNumberInRotateArray(data) << endl;
    return 0;
}
