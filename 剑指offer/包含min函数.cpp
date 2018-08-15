// 用两个栈实现O(1)min函数
// 其中一个栈正常存储原数据，另外一个栈存当前栈中的最小值
class Solution {
public:
    stack<int> data, minval;
    void push(int value) {
        data.push(value);
        if (minval.empty()) {
            minval.push(value);
        } else {
            if (minval.top() < value) {
                minval.push(minval.top());
            } else {
                minval.push(value);
            }
        }
    }
    void pop() {
        data.pop();
        minval.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return minval.top();
    }
};