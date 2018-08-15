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

void change(TreeNode* leftnode, TreeNode* rightnode) {
    if (leftnode == NULL && rightnode == NULL) return;
    if (leftnode == NULL && rightnode != NULL) {
        leftnode = rightnode;
        rightnode = NULL;
        return;
    } else if (leftnode != NULL && rightnode == NULL) {
        rightnode = leftnode;
        leftnode = NULL;
        return;
    } else {
        TreeNode* temp = leftnode;
        leftnode = rightnode;
        rightnode = temp;
        change(leftnode->left, leftnode->right);
        change(rightnode->left, rightnode->right);
    }
}
void Mirror(TreeNode *pRoot) {
    if (pRoot == NULL) return;
    change(pRoot->left, pRoot->right);
}
