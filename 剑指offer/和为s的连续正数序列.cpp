// 可以先从和为s的两个数字理解,连个指针,一个指针在最开始,另一个指针在最后,两数的和和s比较
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    int small = 1, big = 2;
    vector<vector<int> > res;
    if (sum < 3) return res;
    while (small < (sum + 1)/2) {
        int temp = 0;
        for (int i = small; i <= big; ++i) {
            temp += i;
        }
        if (temp < sum) {
            big++;
        } else if (temp > sum) {
            small++;
        } else {
            vector<int> data;
            for (int i = small; i <= big; ++i) {
                data.push_back(i);
            }
            res.push_back(data);
            // 得到一个序列后两个指针都往后移一位
            small++;
            big++;
        }
    }
    return res;
}
