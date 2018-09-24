#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > res;
    if (pRoot == NULL) return res;
    queue<pair<TreeNode*,int> > myqueue;
    myqueue.push(pair<TreeNode*, int>(pRoot, 0));
    int label = 0;
    int height = 0;
    TreeNode* node = pRoot;
    vector<int> LeftToRight;
    stack<int> mystack;
    vector<int> RightToLeft;
    while (!myqueue.empty()) {
        pair<TreeNode*, int> temp = myqueue.front();
        myqueue.pop();
        height = temp.second;
        if (temp.first->left) {
            myqueue.push(pair<TreeNode*, int>(temp.first->left, height+1));
        }
        if (temp.first->right) {
            myqueue.push(pair<TreeNode*, int>(temp.first->right, height+1));
        }
        if (height != label && height != 0) {
            if (height % 2 == 0) {
                RightToLeft.clear();
                while (!mystack.empty()) {
                    RightToLeft.push_back(mystack.top());
                    mystack.pop();
                }
                res.push_back(RightToLeft);
            } else {
                res.push_back(LeftToRight);
                LeftToRight.clear();
            }
            label = height;
        }
        if (height % 2 == 0) {
            LeftToRight.push_back(temp.first->val);
        } else {
            mystack.push(temp.first->val);
        }
    }
    if (!mystack.empty()) {
        RightToLeft.clear();
        while (!mystack.empty()) {
            RightToLeft.push_back(mystack.top());
            mystack.pop();
        }
        res.push_back(RightToLeft);
    }
    if (LeftToRight.size() != 0) res.push_back(LeftToRight);
    return res;
}