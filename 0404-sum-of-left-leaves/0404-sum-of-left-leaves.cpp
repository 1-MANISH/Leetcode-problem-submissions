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
    int helper(TreeNode* root, bool flag){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL){
            return flag ? root->val:0;
        }
        int l_leaves = helper(root->left,true);
        int r_leaves = helper(root->right,false);

        return l_leaves+r_leaves;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)return 0;
        return helper(root,false);
    }
};