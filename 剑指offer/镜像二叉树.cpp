#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
// 对节点为空的情况进行判断
void change(TreeNode* head, TreeNode* leftnode, TreeNode* rightnode) {
    if (leftnode == NULL && rightnode == NULL) return;
    if (leftnode == NULL && rightnode != NULL) {
        head->left = rightnode;
        head->right = NULL;
        change(rightnode, rightnode->left, rightnode->right);
    } else if (leftnode != NULL && rightnode == NULL) {
        head->right = leftnode;
        head->left = NULL;
        change(leftnode, leftnode->left, leftnode->right);
    } else {
        TreeNode* temp = leftnode;
        head->left = rightnode;
        head->right = temp;
        change(leftnode, leftnode->left, leftnode->right);
        change(rightnode, rightnode->left, rightnode->right);
    }
}
// 注意这里要讲headNode传进去，不能够仅仅是将左右节点进行交换，应该是改变head的左节点和head的右节点
void Mirror(TreeNode *pRoot) {
    if (pRoot == NULL) return;
    change(pRoot, pRoot->left, pRoot->right);
}