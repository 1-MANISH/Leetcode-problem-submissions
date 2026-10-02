
/*
RECURSIVE = 
    i   = 0 ---> N
    j   = 0 ---> M
TABULATION =
    i = N ---> 0
    j = M ---> 0
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m+1,vector<int>(n+1));

        for(int i = m ; i >= 0 ; i--){

            for(int j = n ; j >= 0 ; j--){

                int &ans = dp[i][j];
                //base case
                if(i==m-1 and j==n-1){
                    ans =  1;
                    continue;
                }
                if(i>=m or j>=n){
                    ans =  0;
                    continue;
                }
                // right 
                int ans1 = dp[i][j+1];
                // down
                int ans2 = dp[i+1][j];

                ans = ans1+ans2;
            }
        }
        return dp[0][0];
    }
};