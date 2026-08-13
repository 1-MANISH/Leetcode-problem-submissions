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

    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int preStart,int preEnd ,  int inStart,int inEnd){

        if(preStart>preEnd)return NULL;
        // base case
        auto root = new TreeNode(preorder[preStart]);

        int idx = -1;
        for(int i  = inStart ; i <= inEnd ; i++){
            if(inorder[i]==root->val){
                idx =i;
                break;
            }
        }
        int leftSubTreeSize = idx-inStart;
        root->left = helper(preorder,inorder,preStart+1,preStart+leftSubTreeSize,inStart,idx-1);
        root->right = helper(preorder,inorder,preStart+leftSubTreeSize+1,preEnd,idx+1,inEnd);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
       return helper(preorder,inorder,0,n-1,0,n-1);
    }
};