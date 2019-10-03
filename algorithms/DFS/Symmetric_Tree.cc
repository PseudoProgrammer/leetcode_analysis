/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
class Solution {
// // method 1, 递归方法
//     bool isSymmetric(TreeNode* l, TreeNode* r){
//         // 1, 处理叶子节点
//         if (l == NULL && r == NULL)return true;
//         else if(l == NULL && r != NULL)return false;
//         else if(l != NULL && r == NULL)return false;

//         // 2, 处理非叶子节点
//         // NOTE 1, 记得比较l->val, r->val两者的大小
//         if(l->val == r->val && isSymmetric(l->right, r->left) && isSymmetric(l->left, r->right))return true;
//         else return false;
//     }
    
// public:
//     bool isSymmetric(TreeNode* root) {
//         // 1，处理特殊情况
//         if (root == NULL)return true;
//         // 2，处理一般情况
//         return isSymmetric(root->left, root->right);
//     }
// method 2, 非递归方法
public:
    bool isSymmetric(TreeNode* root){
        // 1, 处理异常值
        //queue<TreeNode*> q;
        if (root == NULL)return true;
        queue<TreeNode*> queue_list;
        //queue<Tree> queue_list;
        queue_list.push(root);
        queue_list.push(root);
        TreeNode* first;
        TreeNode* second;
        while(!queue_list.empty()){
            first = queue_list.front();
            queue_list.pop();
            // 2, 处理单节点情况
            if (queue_list.empty())return false;
            second = queue_list.front();
            queue_list.pop();
            // 3, 处理叶子节点
            if (first == NULL && second == NULL)continue;
            else if (first == NULL && second != NULL)return false;
            else if(first != NULL && second == NULL)return false;
            // 4，处理一般节点
            if (first->val != second->val)return false;
            queue_list.push(first->left);
            queue_list.push(second->right);
            queue_list.push(first->right);
            queue_list.push(second->left);
        }
        return true;
        
    }
};
