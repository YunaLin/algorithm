// 将int转换为string直接使用函数to_string
// 将字符串进行排序以后连接起来即可
#include <iostream>
using namespace std;
bool cmp(string a, string b) {
    return a+b < b+a;
}
string PrintMinNumber(vector<int> numbers) {
    int n = numbers.size();
    vector<string> strs;
    for (int i = 0; i < n; ++i) {
        strs.push_back(to_string(numbers[i]));
    }
    sort(strs.begin(), strs.end(), cmp);
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += strs[i];
    }
    return res;
}

int main() {
    return 0;
}