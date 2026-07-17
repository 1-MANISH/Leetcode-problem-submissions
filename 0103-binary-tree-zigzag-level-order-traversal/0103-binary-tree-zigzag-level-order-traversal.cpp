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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>output;
        if(root==NULL)return output;
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int>nodes;
            for(int i = 0 ; i < n ; i++){
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            if(level%2==0)reverse(nodes.begin(),nodes.end());
            output.push_back(nodes);
            level++;
        }

        return output;
    }
};