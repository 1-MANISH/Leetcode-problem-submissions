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
    pair<bool,int> isBal(TreeNode* root){
        if(root==NULL)return {true,0};
        auto [b1,h1] = isBal(root->left);
        auto [b2,h2] = isBal(root->right);
        if(b1 && b2 && abs(h1-h2)<=1 ){
            return {true,max(h1,h2)+1};
        }else{
            return {false,max(h1,h2)+1};
        }
    }
    bool isBalanced(TreeNode* root) {
        return isBal(root).first;
    }
};