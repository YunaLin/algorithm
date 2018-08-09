// 给出一个前序和中序，要创建一棵二叉树

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};
TreeNode* construct(vector<int> pre, vector<int> vin, int prebegin, int preend, int inbegin, int inend) {
    if (preend < prebegin) return NULL;
    int index = inbegin -1;
    int target = pre[prebegin];
    cout << "target: " << target << endl;
    for (int i = inbegin; i <= inend; ++i) {
        if (vin[i] == target) {
            index = i;
            break;
        }
    }
    TreeNode* newNode = new TreeNode(target);
    int len = index - inbegin;
    // 注意下标，特别是+1和-1的地方
    newNode->left = construct(pre, vin, prebegin+1, prebegin+len, inbegin, index - 1);
    newNode->right = construct(pre, vin, prebegin+len+1,preend, index+1, inend);
    return newNode;
} 

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    int len = pre.size();
    cout << "len:" << len << endl;
    if (len == 0) return NULL;
    int index = 0;
    return construct(pre, vin, 0, len - 1, 0, len - 1);
}

int main() {
    vector<int> pre;
    vector<int> vin;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        pre.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        cin >> num;
        vin.push_back(num);
    }
    TreeNode* tree = reConstructBinaryTree(pre, vin);
    queue<TreeNode*> que;
    if (tree != NULL) que.push(tree);
    while (!que.empty()) {
        TreeNode* topnode = que.front();
        cout << topnode->val << " ";
        que.pop();
        if (topnode->left != NULL) que.push(topnode->left);
        if (topnode->right != NULL) que.push(topnode->right);
    }
    cout << endl;
    return 0;
}
