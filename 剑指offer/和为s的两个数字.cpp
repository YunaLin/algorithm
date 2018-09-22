#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int n = array.size();
    vector<int> res(2, 0);
    int small = 0;
    int big = n - 1;
    int amount = 0;
    int multiply = INT_MAX;
    while (small < big) {
        amount = array[small] + array[big];
        if (amount > sum) {
            big--;
        } else if (amount < sum) {
            small++;
        } else {
            if (array[small] * array[big] < multiply) {
                res[0] = array[small];
                res[1] = array[big];
                multiply = array[small]*array[big];
            }
            // 注意这里的下标移动
            small++;
            big--;
        }
    }
    //  找不到和为s的两个数
    if (res[0] == 0 && res[1] == 0) {
        vector<int> zeros;
        return zeros;
    }
    return res;
}

int main() {
    int n, num;
    vector<int> array;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        array.push_back(num);
    }
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << endl;
    int sum;
    cin >> sum;
    vector<int> res = FindNumbersWithSum(array, sum);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}