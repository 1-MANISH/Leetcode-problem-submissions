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
    
    void findPath(TreeNode* root, TreeNode* target,vector<TreeNode*>&nodes){
        if(root==NULL)return;
        if(root->val==target->val){
            nodes.push_back(root);
            return;
        }
        nodes.push_back(root);
        findPath(root->left,target,nodes);
        findPath(root->right,target,nodes);
        if(nodes.size() && nodes[nodes.size()-1]->val!=target->val)nodes.pop_back();
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        findPath(root,p,a);
        findPath(root,q,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = a.size()-1 , j = b.size()-1 ;
        TreeNode* ans = root;
        while(i>=0 && j>=0){
            if(a[i]->val==b[j]->val) ans = a[i];
            i--;
            j--;
        }
        return ans;
    }
};