vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    // 注意考虑特殊情况
    int n = input.size();
    if (n < k) return res;
    sort(input.begin(), input.end());
    for (int i = 0; i < k; ++i) {
        res.push_back(input[i]);
    }
    return res;
}