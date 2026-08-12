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

    void preOrder(TreeNode* root,vector<TreeNode*>&nodes){
        if(root==NULL)return;
        nodes.push_back(root);
        preOrder(root->left,nodes);
        preOrder(root->right,nodes);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>nodes;
        preOrder(root,nodes);
        for(int  i = 0 ;  i + 1 < nodes.size() ; i++){
            nodes[i]->left=NULL;
            nodes[i]->right = nodes[i+1];
        }
    }
};