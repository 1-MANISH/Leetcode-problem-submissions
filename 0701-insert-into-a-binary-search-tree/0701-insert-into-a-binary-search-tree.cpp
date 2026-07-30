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
    void insert(TreeNode* root,TreeNode* parent,int val){
        if(root==NULL){
            if(parent->val>val)
            parent->left=new TreeNode(val);
            else parent->right=new TreeNode(val);
            return;
        }
        if(root->val>val){
            insert(root->left,root,val);
        }
        else{
            insert(root->right,root,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        insert(root,NULL,val);
        return root;
    }
};