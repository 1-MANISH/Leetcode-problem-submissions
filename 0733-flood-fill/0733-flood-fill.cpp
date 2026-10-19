class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        int prevColor =image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        image[sr][sc]=color;
       
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            int rows[4] = {0,-1,0,+1};
            int cols[4] = {-1,0,+1,0};
            for(int i = 0 ;i < 4;i++){
                int newRow = r+rows[i];
                int newCol = c+cols[i];
                if(newRow>=0 and newRow<image.size() and newCol>=0 and newCol<image[0].size() and !visited[newRow][newCol] and image[newRow][newCol]==prevColor){
                    image[newRow][newCol]=color;
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=true;
                }
            }
        }
        return image;
    }
};