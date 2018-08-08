class Solution {
public:
    int Fibonacci(int n) {
        vector<int> arr(100, 0);
        arr[1] = 1;
        for (int i = 2; i <= n; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};