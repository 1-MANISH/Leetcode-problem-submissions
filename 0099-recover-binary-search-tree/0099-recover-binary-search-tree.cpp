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
    void inOrder(TreeNode* root,vector<TreeNode*>&nodes){
        if(root==NULL)return;
        inOrder(root->left,nodes);
        nodes.push_back(root);
        inOrder(root->right,nodes);
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>nodes;
        inOrder(root,nodes);
        
        TreeNode* a,*b =NULL;
        for(int i = 0 ; i < nodes.size()-1;i++ ){
            if(nodes[i]->val > nodes[i+1]->val){
                if(a==NULL){
                    a = nodes[i];
                    b = nodes[i+1];
                }else{
                    b = nodes[i+1];
                }
            }
        }
        swap(a->val,b->val);

        return;

    }
};