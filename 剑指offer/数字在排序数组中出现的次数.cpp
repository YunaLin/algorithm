// 统计数字在排序数组中出现的次数
// int GetNumberOfK(vector<int> data ,int k) {
//     int n = data.size();
//     int res = 0;
//     for (int i = 0; data[i] <= k; ++i) {
//         if (data[i] == k) ++res;
//     }
//     return res;
// }
#include <iostream>
#include <vector>
using namespace std;

int getFirst(vector<int> data, int k, int begin, int end) {
    if (begin > end) return -1;
    int mid = (begin + end)/2;
    int mid_value = data[mid];
    if (mid_value == k) {
        if (mid == 0 || (mid > 0 && data[mid - 1] != k))
            return mid;
        else
            end = mid - 1;
    } else if (k > mid_value) {
        begin = mid + 1;
    } else {
        end = mid - 1;
    }
    return getFirst(data, k, begin, end);
}
int getLast(vector<int> data, int k, int begin, int end) {
    if (begin > end) return -1;
    int mid = (begin + end)/2;
    int mid_value = data[mid];
    int n = data.size();
    if (mid_value == k) {
        if (mid == n - 1 || (mid < n -1  && data[mid + 1] != k))
            return mid;
        else
            begin = mid + 1;
    } else if (k > mid_value) {
        begin = mid + 1;
    } else {
        end = mid - 1;
    }
    return getLast(data, k, begin, end);
}
int GetNumberOfK(vector<int> data, int k) {
    int first = getFirst(data, k, 0, data.size() - 1);
    int last = getLast(data, k, 0, data.size() - 1);
    int res = -1;
    if (first > -1 && last > -1) {
        res = last - first + 1;
    }
    return res;
}

int main() {
    vector<int> data;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        data.push_back(num);
    }
    int k;
    cin >> k;
    cout << GetNumberOfK(data, k) << endl;
}