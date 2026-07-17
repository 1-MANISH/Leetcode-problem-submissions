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
    int depth(TreeNode* root){
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            level++;
        }
        return level;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        return abs(leftDepth-rightDepth)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};