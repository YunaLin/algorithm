// 当遇到二叉搜索树的时候,考虑用中序遍历解决相关的问题
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, TreeNode* &res) {
        if (root) {
            inorder(root->left, res);
            count--;
            if (count == 0) res = root;
            inorder(root->right, res);
        }
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (!pRoot || k < 1) return NULL;
        count = k;
        TreeNode* res = NULL;
        inorder(pRoot, res);
        return res;
    }
private:
    int count;
};