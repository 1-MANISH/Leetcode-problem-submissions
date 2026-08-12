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
    vector<TreeNode*>nodes;
    void inOrder(TreeNode* root){
        if(root==NULL)return;
        inOrder(root->left);
        nodes.push_back(root);
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inOrder(root);
        TreeNode* a=NULL , *b = NULL;
        for(int i = 0 ; i+1 < nodes.size() ;i++){
            if(nodes[i]->val > nodes[i+1]->val){
                if(a==NULL){
                    a = nodes[i];
                    b = nodes[i+1];
                }
                else{
                    b = nodes[i+1];
                }
            }
        }
        swap(a->val,b->val);// only values 
    }
};