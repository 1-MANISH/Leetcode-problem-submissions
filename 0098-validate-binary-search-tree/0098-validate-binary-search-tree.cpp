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
    int maxer(TreeNode* root){
        if(root==NULL)return INT_MIN;
        int lmx = maxer(root->left);
        int rmx = maxer(root->right);
        return max(root->val,max(lmx,rmx));
    }
    int miner(TreeNode* root){
        if(root==NULL)return INT_MAX;
        int lmn = miner(root->left);
        int rmn = miner(root->right);
        return min(root->val,min(lmn,rmn));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;

        int lmx = maxer(root->left);
        int rmn = miner(root->right);

        if(root->left==NULL && root->right==NULL)return  isValidBST(root->left) && isValidBST(root->right);
        else if(root->left==NULL && root->right!=NULL)return root->val<rmn && isValidBST(root->left) && isValidBST(root->right);
        else if(root->left!=NULL && root->right==NULL)return root->val>lmx && isValidBST(root->left) && isValidBST(root->right);
        else return root->val>lmx && root->val<rmn &&  isValidBST(root->left) && isValidBST(root->right);
    }
};