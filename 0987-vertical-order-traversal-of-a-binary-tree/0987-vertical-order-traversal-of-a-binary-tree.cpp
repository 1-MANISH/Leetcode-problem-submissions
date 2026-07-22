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
    vector<vector<int>> verticalTraversal(TreeNode* root) {        
        vector<vector<int>>output;
        if(root==NULL)return output;
        unordered_map<int,vector<pair<int,int>>>mp; //dist -> nodes[{level,value}]
        queue<tuple<TreeNode*,int,int>>q; //{node,dist,level} -> horizontal distance
        q.push({root,0,0});
        int start = INT_MAX ,  end = INT_MIN;
        while(!q.empty()){
            auto[node,dist,level] = q.front();
            q.pop();
            start = min(start,dist);
            end = max(end,dist);
            mp[dist].push_back({level,node->val});
            if(node->left!=NULL)q.push({node->left,dist-1,level+1});
            if(node->right!=NULL)q.push({node->right,dist+1,level+1});
        }
        for(int dist = start ;dist <=end;dist++){
            auto nodes = mp[dist];
            sort(nodes.begin(),nodes.end());
            vector<int>temp;
            for(auto &e:nodes)temp.push_back(e.second);
            output.push_back(temp);
        }
        return output;
    }
};