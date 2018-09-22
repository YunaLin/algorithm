#include <iostream>
#include <string>
using namespace std;

string LeftRotateString(string str, int n) {
    string res = str;
    int len = str.length();
    // 对len进行判断,避免下面出现除0的情况
    if (len <= 1) return str;
    int index = 0;
    for (int i = n % len; i < len; ++i) {
        res[index++] = str[i];
    }
    for (int i = 0; i < n % len; ++i) {
        res[index++] = str[i];
    }
    return res;
}
int main() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    cout << LeftRotateString(str, n) << endl;
    return 0;
}