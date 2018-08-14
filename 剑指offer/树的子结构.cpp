// 判断B是不是A的子结构
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <queue>
bool judge(TreeNode* head1, TreeNode* head2) {
    if (head1 == NULL && head2 != NULL) return false;
    if (head1 != NULL && head2 == NULL) return true;
    if (head1 == NULL && head2 == NULL) return true;
    if (head1->val != head2->val) return false;
    return judge(head1->left, head2->left) && judge(head1->right, head2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot1 == NULL || pRoot2 == NULL) return false;
    queue<TreeNode*> que;
    que.push(pRoot1);
    TreeNode* node;
    bool result = false;
    while (!que.empty()) {
        node = que.front();
        que.pop();
        if (node->left != NULL) que.push(node->left);
        if (node->right != NULL) que.push(node->right);
        if (node->val == pRoot2->val) {
            result = judge(node, pRoot2);
        }
        if (result == true) return true;
    }
    return false;
}