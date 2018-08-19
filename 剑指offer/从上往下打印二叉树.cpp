/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
vector<int> PrintFromTopToBottom(TreeNode* root) {
    queue<TreeNode*> que;
    vector<int> result;
    if (root == NULL) return result;
    que.push(root);
    TreeNode* node = root;
    while (!que.empty()) {
        node = que.front();
        result.push_back(node->val);
        que.pop();
        if (node->left != NULL)
            que.push(node->left);
        if (node->right != NULL)
            que.push(node->right);
    }
    return result;
}