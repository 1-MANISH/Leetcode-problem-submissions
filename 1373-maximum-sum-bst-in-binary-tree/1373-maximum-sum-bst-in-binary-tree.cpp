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

struct Data{
  bool isBst=true;
  int sum = 0;
  int minimum = INT_MAX;
  int maximum = INT_MIN;
  int maximumSumBST=0;
};

class Solution {
public:
    Data maxisumBSTSUM(TreeNode * root){
        if(root==NULL)return Data();
        
        Data left = maxisumBSTSUM(root->left);
        Data right = maxisumBSTSUM(root->right);
        
        Data ans;
        ans.minimum = min(root->val , min(left.minimum,right.minimum));
        ans.maximum = max(root->val , max(left.maximum,right.maximum));
        ans.isBst = left.maximum< root->val && right.minimum>root->val && left.isBst && right.isBst;
        ans.sum = left.sum+right.sum+root->val;
        if(ans.isBst){
            ans.maximumSumBST = max(ans.sum ,max(left.maximumSumBST,right.maximumSumBST)) ;
        }else{
            ans.maximumSumBST = max(left.maximumSumBST,right.maximumSumBST);
        }
        
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        return maxisumBSTSUM(root).maximumSumBST;
    }
};