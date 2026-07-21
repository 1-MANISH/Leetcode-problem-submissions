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

    static bool cap(pair<int,int>&p,pair<int,int>&q){
        if(p.first==q.first){// level same
            return p.second<q.second;//value chota phle
        }else return p.first<q.first;// chota phle always
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>output;
        queue<tuple<TreeNode*,int,int>>q;//{node,dist,level}
        unordered_map<int,vector<pair<int,int>>>mp;
        int start = INT_MAX ,end = INT_MIN;
        q.push({root,0,0});
        while(!q.empty()){
            auto [curr,dist,level] = q.front();
            q.pop();
            mp[dist].push_back({level,curr->val});
            start = min(start,dist);
            end = max(end,dist);
            if(curr->left!=NULL)q.push({curr->left,dist-1,level+1});
            if(curr->right!=NULL)q.push({curr->right,dist+1,level+1});
        }
        // sort
        // level - alag then p first
        // value - level equal then
        for(int dist=start ;dist<=end;dist++){
            auto nodes = mp[dist];
            sort(nodes.begin(),nodes.end(),cap);
            vector<int>temp;
            for(auto &ele:nodes)temp.push_back(ele.second);
            output.push_back(temp);
        }
        return output;
    }
};