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
    vector<int> rightSideView(TreeNode* root) {
         vector<int>output;
        if(root==NULL)return output;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size= q.size(), i =0;
            while(i<size){
                TreeNode* node = q.front();
                q.pop();
                if(i==size-1)output.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                i++;
            }
        }
        return output;
    }
};