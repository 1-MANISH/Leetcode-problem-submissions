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
    int MIN(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){// key not found
            return NULL;
        }
        if(root->val==key){
            // case:1 | its leaf node which we trying to delete
            if(root->left==NULL && root->right==NULL)
                return NULL;

            // case:2 | its only have left subtrees
            if(root->left!=NULL && root->right==NULL)
                return root->left;
            
            // case:3 | its only have right subtrees
            if(root->left==NULL && root->right!=NULL)
                return root->right;

            // case:4 | its has both lefy and right
            //option-1: finding minimum from right - swap to this node , delete this node
            int right_min = MIN(root->right);
            root->val =right_min;
            root->right =  deleteNode(root->right,right_min);
            return root;

        }else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};