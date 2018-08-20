int FindGreatestSumOfSubArray(vector<int> array) {
    int n = array.size();
    if (n == 0) return 0;
    int sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        // 如果是数组有正有负的话，sum如下进行判断，如果只有正数，则当sum小于0的时候置为0
        sum = sum + array[i] > array[i] ? sum + array[i] : array[i];
        max = sum > max ? sum : max;
    }
    return max;
}