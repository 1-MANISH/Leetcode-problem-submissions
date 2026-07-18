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
    unordered_map<long long ,int>mapping;
    void helper(TreeNode* root){
        if(root==NULL)return;
        mapping[root->val]++;
        helper(root->left);
        helper(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        int mx = 0;
        for(auto &p:mapping){
            mx = max(mx,p.second);
        }
        vector<int>output;
        for(auto &p:mapping){
            if(p.second==mx){
                output.push_back(p.first);
            }
        }
        return output;
    }
};