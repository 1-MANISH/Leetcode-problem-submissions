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
    // inorder of bst always sorted - but here 2 mismatch - at any position
    TreeNode *a=NULL , *b = NULL, *prev = NULL;
    void inOrder(TreeNode* root){
        if(root==NULL)return;
        inOrder(root->left);
        if(prev!=NULL){
            if(prev->val>root->val){
                if(a==NULL){
                    a = prev;
                    b = root;
                }else{
                    b = root;
                }
            }
        }
        prev=root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap(a->val,b->val);// only values 
    }
};