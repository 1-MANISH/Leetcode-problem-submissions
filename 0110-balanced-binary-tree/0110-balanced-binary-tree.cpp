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
    bool isBal(TreeNode* root,int &h){
        if(root==NULL)return true;
        int lh = 0, rh = 0;
        if(!isBal(root->left,lh))return false;
        if(!isBal(root->right, rh))return false;

        h = max(lh,rh)+1;

        if(abs(lh-rh)<=1)return true;
        return false;

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int h = 0 ;
        return isBal(root,h);
    }
};