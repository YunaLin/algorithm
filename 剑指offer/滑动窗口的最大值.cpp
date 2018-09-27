class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        // 当提示超出内存限制的时候,优先考虑不合法的情况是否已经进行判断和处理
        if (num.size() == 0 || size < 1 || num.size() < size) return res;
        int n = num.size();
        res.resize(n - size + 1, 0);
        int max = INT_MIN;
        for (int i = 0; i <= n - size; ++i) {
            max = INT_MIN;
            for (int j = i; j < i + size; ++j) {
                max = max > num[j] ? max:num[j];
            }
            res[i] = max;
        }
        return res;
    }
};