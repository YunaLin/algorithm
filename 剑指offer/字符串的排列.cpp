// 输入abc,则输出由a,b,c所能够排列的所有可能的字符串:abc,acb,bac,bca,cab和cba
class Solution {
public:
    vector<string> Permutation(string str) {
        // 存储在set中从而解决排序和重复的问题
        set<string> res;
        findPermutation(res, str, 0);
        vector<string> ans;
        for (auto it = res.begin(); it != res.end(); ++it)
            ans.push_back(*it);
        return ans;
    }
    void findPermutation(set<string>& res, string str, int begin) {
        int n = str.size();
        if (begin == n - 1) {
            res.insert(str);
            return;
        }
        int i = begin;
        char temp;
        while (str[i] != '\0') {
            temp = str[begin];
            str[begin] = str[i];
            str[i] = temp;
            findPermutation(res, str, begin+1);
            temp = str[i];
            str[i] = str[begin];
            str[begin] = temp;
            i++;
        }
    }
};