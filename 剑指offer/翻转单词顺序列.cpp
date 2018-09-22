#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReverseSentence(string str) {
    string reverse = str;
    int n = str.length();
    // 先全部反转一遍
    for (int i = 0; i < n; ++i) {
        reverse[i] = str[n - i - 1];
    }
    string res = reverse;
    vector<int> indexes;
    indexes.push_back(-1);
    int emptyNum = 0;
    // 将空格的下标存储起来,包括头部和尾部空格
    for (int i = 0; i < n; ++i) {
        if (reverse[i] == ' ') {
            indexes.push_back(i);
            emptyNum++;
        }
    }
    indexes.push_back(n);
    int count = 0;
    emptyNum += 2;
    // 每两个空格之间的单词进行翻转
    for (int i = 1; i < emptyNum; ++i) {
        for (int j = indexes[i - 1] + 1; j < indexes[i]; ++j) {
            res[j] = reverse[indexes[i-1] + indexes[i] - j];
        }
    }
    return res;
}
int main() {
    string str;
    getline(cin, str);
    cout << ReverseSentence(str) << endl;
    return 0;
}