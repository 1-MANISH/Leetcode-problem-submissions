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
    int MAX(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL)return NULL;
        
        //left me chalo
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){// right me chalo
            root->right=deleteNode(root->right,key);
        }else{

            // leaf node need to delete
            if(root->left==NULL and root->right==NULL){
                return NULL;
            }
            // node with only left
            if(root->left!=NULL and root->right==NULL){
                return root->left;
            }
            //  node with only right
            if(root->left==NULL and root->right!=NULL){
                return root->right;
            }
            // node with both - left and right
            int mx = MAX(root->left);
            root->val = mx;
            // delete mx from root->left
            root->left=deleteNode(root->left,mx);
            
        }
        return root; 
    }
};