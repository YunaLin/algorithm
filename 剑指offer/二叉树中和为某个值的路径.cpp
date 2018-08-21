// 递归实现，需要注意的是路径必须是到达叶子节点的路径
vector< vector<int> > result;
vector<int> path;
void dfs(TreeNode* root, int expectNumber) {
    if (root == NULL) return;
    path.push_back(root->val);
    if (root->val == expectNumber && root->left == NULL && root->right == NULL)
        result.push_back(path);
    else {
        if (root->left) dfs(root->left, expectNumber - root->val);
        if (root->right) dfs(root->right, expectNumber - root->val);
    }
    // 最终结束的时候需要回退一个节点回到父节点
    path.pop_back();
}
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    dfs(root, expectNumber);
    return result;
}
