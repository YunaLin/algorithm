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

vector<vector<int> > Print(TreeNode* pRoot) {
    queue<pair<TreeNode*, int> > myqueue;
    vector<vector<int> > res;
    if (pRoot == NULL) return res;
    myqueue.push(make_pair(pRoot, 1));
    TreeNode* node = NULL;
    int height = 0;
    int label = 1;
    vector<int> row;
    while (!myqueue.empty()) {
        node = myqueue.front().first;
        height = myqueue.front().second;
        myqueue.pop();
        if (height == label) {
            row.push_back(node->val);
        } else {
            res.push_back(row);
            row.clear();
            row.push_back(node->val);
            label = height;
        }
        if (node->left) {
            myqueue.push(make_pair(node->left, height+1));
        }
        if (node->right) {
            myqueue.push(make_pair(node->right, height+1));
        }
    }
    res.push_back(row);
    return res;
}