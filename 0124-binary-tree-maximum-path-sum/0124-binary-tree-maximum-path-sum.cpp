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
    int straightPathSum=0;
    int maxPathSum=INT_MIN;
};

class Solution {
public:

    Data maxPath(TreeNode* root){
        if(root==NULL){
            return Data();
        }
        Data leftAns = maxPath(root->left);
        Data rightAns = maxPath(root->right);

        Data ans;
        ans.straightPathSum = max(max(leftAns.straightPathSum,rightAns.straightPathSum)+root->val ,root->val);
        ans.maxPathSum = max( max(ans.straightPathSum,leftAns.straightPathSum+rightAns.straightPathSum+root->val) , max(leftAns.maxPathSum,rightAns.maxPathSum) );

        return ans;
    }
    int maxPathSum(TreeNode* root) {
        Data ans = maxPath(root);
        return max(ans.straightPathSum,ans.maxPathSum);
    }
};