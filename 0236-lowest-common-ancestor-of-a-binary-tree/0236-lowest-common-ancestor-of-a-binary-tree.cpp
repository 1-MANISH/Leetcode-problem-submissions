/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;

        if(root==p or root==q)return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // at this node (p and q find)
        if(left!=NULL && right!=NULL)return root;

        // p found
        if(left!=NULL && right==NULL)return left;

        // q found
        if(left==NULL && right!=NULL)return right;

        // nothing found
        return NULL;
    }
};