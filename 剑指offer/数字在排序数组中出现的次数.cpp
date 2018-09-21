// 统计数字在排序数组中出现的次数
int GetNumberOfK(vector<int> data ,int k) {
    int n = data.size();
    int res = 0;
    for (int i = 0; data[i] <= k; ++i) {
        if (data[i] == k) ++res;
    }
    return res;
}