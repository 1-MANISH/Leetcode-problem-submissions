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
    int count = 1;
    void inOrder(TreeNode* root,int &ans,int &k){
        if(root==NULL)return;
        inOrder(root->left,ans,k);
        if(count==k){
            ans=root->val;
        }
        count++;
        inOrder(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return -1;
        int ans;
        inOrder(root,ans,k);
        return ans;

    }
};