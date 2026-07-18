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

    void shortestPathLength(TreeNode* root,int &path_length,int path){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            path_length = min(path_length,path);
            return;
        }
        shortestPathLength(root->left,path_length,path+1);
        shortestPathLength(root->right,path_length,path+1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int path_length = INT_MAX;
        shortestPathLength(root,path_length,1);
        return path_length;
    }
};