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
    void Ancestor(TreeNode* root,TreeNode* target,vector<TreeNode*>&nodes){
        if(root==NULL)return;
        nodes.push_back(root);
        if(root->val > target->val){
            Ancestor(root->left,target,nodes);
        }
        else if(root->val < target->val){
            Ancestor(root->right,target,nodes);
        }
        else{
            return;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        Ancestor(root,p,a);
        Ancestor(root,q,b);
        TreeNode* ans  = root;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = a.size()-1, j = b.size()-1;
        while(i>=0 && j>=0){
            if(a[i]->val==b[j]->val)ans=a[i];
            i--;
            j--;
        }
        return ans;
    }
};