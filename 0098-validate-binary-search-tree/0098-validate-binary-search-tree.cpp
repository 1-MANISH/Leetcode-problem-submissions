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
    vector<int>inorder;
    void inOrder(TreeNode* root){
        if(root==NULL)return;
        inOrder(root->left);
        inorder.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i = 1 ; i <inorder.size();i++){
            if(inorder[i-1]>=inorder[i])return false;
        }
        return true;
    }
};