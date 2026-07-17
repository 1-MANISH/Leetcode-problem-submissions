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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>output;
        if(root==NULL)return output;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            output.push_back(temp);
        }
        reverse(output.begin(),output.end());
        return output;
    }
};