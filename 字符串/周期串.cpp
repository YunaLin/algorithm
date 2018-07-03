#include <iostream>
#include <vector>
using namespace std;

// 输出给定字符串的最小周期
// 思路: 遍历,当遍历到的字符和最后的字符相同的时候,对倒序字符和前面已经遍历过的字符进行比较
// 如果相同,则为周期,否则继续遍历,不断找与最后一个字符相同的字符

int main() {
    string str;
    cin >> str;
    int res = 0;
    int len = str.length();
    int count = 0;
    vector<char> head;
    bool flag = false;
    while (count < len) {
        head.push_back(str[count]);
        if (str[count] == str[len - 1]) {
            flag = true;
            for (int i = 0; i <= count; ++i) {
                if (head[i] != str[len - count + i - 1]) {
                    flag = false;
                    break;
                }
            }
        }
        count++;
        if (flag == true) break;
    }
    cout << count << endl;
    return 0;
}