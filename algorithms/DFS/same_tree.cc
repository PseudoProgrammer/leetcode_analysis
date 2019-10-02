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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 树的遍历方式的知识点考察，两棵树按照相同方式进行遍历比较，不同则返回false，遍历结束则返回true
        // 本题采用前序遍历方式进行比较
        // 1, 先处理特殊情况，NULL变量没有val，left，right
        if (p == NULL && q != NULL)return false;
        else if(p != NULL && q == NULL)return false;
        else if(p == NULL && q == NULL)return true;
        // 2, 根先遍历
        if (p->val != q->val)return false;
        // 3, 左孩子节点中遍历
        if (!isSameTree(p->left, q->left))return false;
        // 4, 右孩子节点后遍历
        if (!isSameTree(p->right, q->right))return false;
        return true;
    }
};
