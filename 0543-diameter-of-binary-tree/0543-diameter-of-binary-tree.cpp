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
    // height diameter
    pair<int,int> helper(TreeNode* root){
        if(root==NULL)return {0,0};
        auto[lh,ld] = helper(root->left);
        auto [rh,rd] = helper(root->right);
        // either take root or exclude root
        return {max(lh,rh)+1 , max(lh+rh,max(ld,rd))};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};