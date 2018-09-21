// 字符串中第一个出现一次的字符
int FirstNotRepeatingChar(string str) {
    vector<int> accurTimes(200, 0);
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        accurTimes[str[i] - '0']++;
    }
    for (int i = 0; i < n; ++i) {
        if (accurTimes[str[i] - '0'] == 1)
            return i;
    }
    return -1;
}