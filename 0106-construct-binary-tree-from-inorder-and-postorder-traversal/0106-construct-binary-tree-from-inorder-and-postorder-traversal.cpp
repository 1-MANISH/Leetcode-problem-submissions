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
    TreeNode* helper(vector<int>&postorder,vector<int>&inorder,int post_start,int post_end ,  int in_start,int in_end){

        if(in_start>in_end)return NULL;
        // base case
        auto root = new TreeNode(postorder[post_end]);

        int idx = mapping[root->val];

        int left_sub_tree_size = idx-in_start;

        root->left = helper(postorder,inorder,post_start,post_start+left_sub_tree_size-1,in_start,idx-1);
        root->right = helper(postorder,inorder,post_start+left_sub_tree_size,post_end-1,idx+1,in_end);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i  =0 ; i< n ; i++)mapping[inorder[i]]=i;
        return helper(postorder,inorder,0,n-1,0,n-1);
    }
};