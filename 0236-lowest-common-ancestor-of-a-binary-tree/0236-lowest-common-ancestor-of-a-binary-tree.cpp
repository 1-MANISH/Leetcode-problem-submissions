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
    bool isFind = false;
    void Ancestor(TreeNode* root,TreeNode* node,vector<TreeNode*>&anc){
        if(root==NULL){
            return;
        }

        if(root->val==node->val){
            anc.push_back(root);
            isFind=true;
            return;
        };
        if(isFind)return;
        anc.push_back(root);
        Ancestor(root->left,node,anc);
        if(isFind)return;
        Ancestor(root->right,node,anc);
        if(isFind)return;
        anc.pop_back();

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        Ancestor(root,p,a);
        isFind=false;
        Ancestor(root,q,b);
        reverse(a.begin() , a.end());
        reverse(b.begin() , b.end());
        int i = a.size()-1 , j = b.size()-1;
        TreeNode* ans = root;
        while(i>=0 && j>=0){
            if(a[i]->val==b[j]->val)ans = a[i];
            i--;
            j--;
        }
        return ans;

    }
};