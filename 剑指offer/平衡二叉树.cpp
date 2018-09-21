class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL) return true;
        int left = calculate(pRoot->left) + 1;
        int right = calculate(pRoot->right) + 1;
        if (abs(left - right) > 1) return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int calculate(TreeNode* root) {
        if (root == NULL) return 0;
        return max(calculate(root->left) + 1, calculate(root->right) + 1);
    }
};