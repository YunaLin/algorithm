// 利用一个栈对输入序列进行一个模拟
// 当输入序列的栈顶是输出序列的当前所在数字时，将当前栈顶pop掉，然后将输入的数字继续push到栈中

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    int n = pushV.size();
    if (n == 0) return true;
    stack<int> myStack;
    int j = 0;
    myStack.push(pushV[0]);
    for (int i = 1; i < n; ++i) {
        if (myStack.top() == popV[j]) {
            myStack.pop();
            j++;
        }
        myStack.push(pushV[i]);
    }
    while (j < n) {
        if (myStack.top() == popV[j]) {
            myStack.pop();
            j++;
        } else {
            return false;
        }

    }
    if (myStack.empty()) return true;
    else return false;
}