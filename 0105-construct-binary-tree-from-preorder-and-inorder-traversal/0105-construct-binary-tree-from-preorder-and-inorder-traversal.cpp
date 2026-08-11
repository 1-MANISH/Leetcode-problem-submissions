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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size()==0){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        int idx = -1;
        for(int i = 0 ; i < inorder.size() ; i++){
            if(inorder[i]==root->val){
                idx=i;
                break;
            }
        }

        vector<int>porder_left;//[1,idx]
        vector<int>porder_right;//[idx+1,last last]
        vector<int>inorder_left;//[0,idx-1]
        vector<int>inorder_right;//[idx+1,till last]

        for(int i  = 1 ; i <=idx ; i++)porder_left.push_back(preorder[i]);
        for(int i  = idx+1 ; i <preorder.size() ; i++)porder_right.push_back(preorder[i]);

        for(int i  = 0 ; i <idx ; i++)inorder_left.push_back(inorder[i]);
        for(int i  = idx+1 ; i <inorder.size() ; i++)inorder_right.push_back(inorder[i]);

        root->left = buildTree(porder_left,inorder_left);
        root->right = buildTree(porder_right,inorder_right);

        return root;

    }
};