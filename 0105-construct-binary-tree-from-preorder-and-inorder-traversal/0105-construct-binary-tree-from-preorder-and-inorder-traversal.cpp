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
    unordered_map<int,int>mapping;//ele->index
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int pre_start,int pre_end ,  int in_start,int in_end){

        if(pre_start>pre_end)return NULL;
        // base case
        auto root = new TreeNode(preorder[pre_start]);

        int idx = mapping[root->val];

        int left_sub_tree_size = idx-in_start;

        root->left = helper(preorder,inorder,pre_start+1,pre_start+left_sub_tree_size,in_start,idx-1);
        root->right = helper(preorder,inorder,pre_start+left_sub_tree_size+1,pre_end,idx+1,in_end);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i  =0 ; i< n ; i++)mapping[inorder[i]]=i;
        return helper(preorder,inorder,0,n-1,0,n-1);
    }
};