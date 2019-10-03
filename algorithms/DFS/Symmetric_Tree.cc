/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// method 1, 递归方法
    bool isSymmetric(TreeNode* l, TreeNode* r){
        // 1, 处理叶子节点
        if (l == NULL && r == NULL)return true;
        else if(l == NULL && r != NULL)return false;
        else if(l != NULL && r == NULL)return false;

        // 2, 处理非叶子节点
        // NOTE 1, 记得比较l->val, r->val两者的大小
        if(l->val == r->val && isSymmetric(l->right, r->left) && isSymmetric(l->left, r->right))return true;
        else return false;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        // 1，处理特殊情况
        if (root == NULL)return true;
        // 2，处理一般情况
        return isSymmetric(root->left, root->right);
    }
};
