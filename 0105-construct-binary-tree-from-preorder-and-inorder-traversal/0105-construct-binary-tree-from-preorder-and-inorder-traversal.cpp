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

        if(preorder.size()==0)return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);

        int idx = -1;
        for(int i = 0 ; i< inorder.size() ;i++){
            if(inorder[i]==preorder[0]){
                idx = i;
                break;
            }
        }

        vector<int>p_order1;//[1,idx]
        vector<int>p_order2;//[idx+1,n-1];
        vector<int>i_order1;//[0,idx-1]
        vector<int>i_order2;//[idx+1,n-1];

        for(int i = 1 ; i<=idx;i++)p_order1.push_back(preorder[i]);
        for(int i = idx+1;i<preorder.size();i++)p_order2.push_back(preorder[i]);
        for(int i = 0 ; i< idx;i++)i_order1.push_back(inorder[i]);
        for(int i = idx+1 ; i< inorder.size();i++)i_order2.push_back(inorder[i]);

        TreeNode* left_tree = buildTree(p_order1,i_order1);
        TreeNode* right_tree = buildTree(p_order2,i_order2);

        root->left=left_tree;
        root->right=right_tree;

        return root;
    }
};