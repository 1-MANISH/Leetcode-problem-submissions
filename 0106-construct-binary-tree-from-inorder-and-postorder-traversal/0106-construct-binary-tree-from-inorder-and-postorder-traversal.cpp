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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0)return NULL;
        
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);

        int idx = -1;
        for(int i = 0 ; i < inorder.size() ;i++){
            if(inorder[i]==postorder[postorder.size()-1]){
                idx = i;
                break;
            }
        }

        vector<int>p_order1;//[0,idx-1] // left
        vector<int>p_order2;//[idx,n-2]; // right
        vector<int>i_order1;//[0,idx-1] // left
        vector<int>i_order2;//[idx+1,n-1]; // right

        for(int i = 0 ; i<idx;i++)p_order1.push_back(postorder[i]);
        for(int i = idx;i<postorder.size()-1;i++)p_order2.push_back(postorder[i]);
        for(int i = 0 ; i< idx;i++)i_order1.push_back(inorder[i]);
        for(int i = idx+1 ; i< inorder.size();i++)i_order2.push_back(inorder[i]);

        TreeNode* left_tree = buildTree(i_order1,p_order1);
        TreeNode* right_tree = buildTree(i_order2,p_order2);

        root->left=left_tree;
        root->right=right_tree;

        return root;
    }
};