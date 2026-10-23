class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        int prevColor = image[sr][sc];
        image[sr][sc]=color;

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();

            // put its adjacent node which has same color as image[sr][sc](now prevColor);
            int rows[4] = {0,-1,0,+1};
            int cols[4] = {-1,0,+1,0};
            for(int i  = 0 ; i < 4 ; i++){
                int n_r = r + rows[i];
                int n_c = c + cols[i];
                // valid and has same color as prevColor then fill with new color
                if(n_r >= 0 and n_r < image.size() and n_c >= 0 and  n_c < image[0].size() and image[n_r][n_c]==prevColor and !visited[n_r][n_c]){
                    visited[n_r][n_c]=true;
                    image[n_r][n_c]=color;
                    q.push({n_r,n_c});
                }
            }
        }
        return image;
    }
};