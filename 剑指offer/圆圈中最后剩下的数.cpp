// 孩子们的游戏:圆圈中最后剩下的数
int LastRemaining_Solution(int n, int m) {
    list<int> numbers;
    // 考虑特殊情况
    if (n <= 0 || m <= 0) return -1;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(i);
    }
    auto it = numbers.begin();
    // 使用链表实现,注意是循环链表
    while (numbers.size() > 1) {
        for (int i = 1; i < m; ++i) {
            it++;
            if (it == numbers.end())
                it = numbers.begin();
        }
        auto next = ++it;
        if (next == numbers.end())
            next = numbers.begin();
        --it;
        numbers.erase(it);
        it = next;
    }
    return *it;
}