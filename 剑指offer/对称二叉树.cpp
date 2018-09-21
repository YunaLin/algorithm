class Solution {
public:
    bool symmetry(TreeNode* leftnode, TreeNode* rightnode) {
        if (leftnode == NULL && rightnode == NULL) return true;
        if (leftnode == NULL || rightnode == NULL) return false;
        if (leftnode->val != rightnode->val) return false;
        return symmetry(leftnode->left, rightnode->right) && symmetry(leftnode->right, rightnode->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL) return true;
        return symmetry(pRoot->left, pRoot->right);
    }

};