/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tail;
    void preOrder(TreeNode* root){
        if(root==NULL)return;
        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;
        if(tail==NULL)tail=root;
        else{
            tail->right=root;
            tail=root;
        } 
        tail->left=NULL;
        preOrder(leftTree);
        preOrder(rightTree);
    }
    void flatten(TreeNode* root) {
        tail = NULL;
        preOrder(root);
    }
};