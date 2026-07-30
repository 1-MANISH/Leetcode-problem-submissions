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

    void inOrder(TreeNode* root, long long &prev,bool &ans){
        if(root==NULL)return;
        inOrder(root->left,prev,ans);
        
        if(root->val<=prev){
            ans=false;
        }
        prev=root->val;
       
        inOrder(root->right,prev,ans);

    }
    bool isValidBST(TreeNode* root) {
        
        vector<int>inorder;
        bool ans = true;
        long long  prev=LLONG_MIN;
        inOrder(root,prev,ans);
        return ans;

    }
};