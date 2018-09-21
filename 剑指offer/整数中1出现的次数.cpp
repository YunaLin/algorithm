int NumberOf1Between1AndN_Solution(int n)
{
    int res = 0;
    if (n < 1) return res;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp) {
            if (temp % 10 == 1) res++;
            temp /= 10;
        }
    }
    return res;
}