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
    TreeNode* makeBalanceTree(vector<int>&nums,int s,int e){
        if(s>e)return NULL;

        int m = s+(e-s)/2;
        TreeNode* node = new TreeNode(nums[m]);

        node->left = makeBalanceTree(nums,s,m-1);
        node->right = makeBalanceTree(nums,m+1,e);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBalanceTree(nums,0,nums.size()-1);
    }
};