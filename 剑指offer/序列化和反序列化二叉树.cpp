struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
private:
    TreeNode* Decode(char* &str) {
        if (*str == '#') {
            str++;
            return NULL;
        }
        int num = 0;
        while (*str != ',') {
            num = num*10 + (*str - '0');
            str++;
        }
        str++;   // ','
        TreeNode* root = new TreeNode(num);
        root->left = Decode(str);
        root->right = Decode(str);
        return root;
    }
public:
    char* Serialize(TreeNode *root) {
        // 此处不要用root == NULL
        if (!root) return "#";
        string r = to_string(root->val);
        r.push_back(',');
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
        char* res = new char[strlen(left)+strlen(right)+r.length()];
        strcpy(res, r.c_str());  // 需要将string转换为char*
        strcat(res, left);
        strcat(res, right);
        return res;
    }
    TreeNode* Deserialize(char *str) {
        return Decode(str);
    }
};