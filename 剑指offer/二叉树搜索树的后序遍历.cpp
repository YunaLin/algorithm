// 给定一个序列，判断是不是二叉搜索树的二叉便利结果
// 首先序列的最后一个数字是root，找到第一个比root大的数字，其之前为左子树
// 其之后为右子树，如果右子树出现比root小的则返回false
// 递归进行判断，需要注意一开始的输入如果是空的话返回false
// 递归实现
bool VerifySquenceOfBST(vector<int> sequence) {
    int n = sequence.size();
    if (n == 0) return false;
    return Verify(sequence);
}
bool Verify(vector<int> sequence) {    
    int n = sequence.size();
    if (n == 0 || n == 1) return true;
    int root = sequence[n - 1];
    vector<int> left;
    vector<int> right;
    int i = 0;
    for (i = 0; i < n - 1; ++i) {
        if (sequence[i] < root) left.push_back(sequence[i]);
        else break;
    }
    for (i; i < n -1; ++i) {
        if (sequence[i] < root) return false;
        else right.push_back(sequence[i]);
    }
    return Verify(left) && Verify(right);
}