#include <string>
#include <iostream>
using namespace std;

bool isDigit(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    return false;
}

int StrToInt(string str) {
    int flag = 1, index = 0, res =0;
    int len = str.length();
    if (len <= 0) return 0;
    if (str[0] == '-') {
        index++;
        flag = -1;
    }
    if (str[0] == '+') {
        index++;
        flag = 1;
    }
    for (; index < len; ++index) {
        if (!isDigit(str[index])) {
            return 0;
        }
        res = res * 10 + str[index] - '0';
    }
    return res*flag;
}

int main() {
    string str;
    cin >> str;
    int res = StrToInt(str);
    cout << res << endl;
    return 0;
}