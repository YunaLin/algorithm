#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
    // 将可以用switch解决的问题转换为string常量数组
    // 学会用常量表简化代码
    string str = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL:'ZXCVBNM,./";
    char ch;
    int len = str.length(), i;
    while ((ch = getchar()) != EOF) {
        for (i = 0; ch != str[i] && i < len; ++i);
        if (ch == str[i]) cout << str[i-1];
        else cout << ch;
    }
    cout << endl;
    return 0;
}