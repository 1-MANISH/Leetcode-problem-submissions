
const int N = 1e3;
int dp[N][N];

class Solution {
public:

    int solve(int i , int j , string &text1, string &text2){

        // base case
        if(i>=text1.size() or j >= text2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // character match
        int ans =  0;
        if(text1[i]==text2[j]){
            ans = 1 + solve(i+1,j+1,text1,text2);
        }else{
            // no match
            // lets move i forward and check
            int ans1 = solve(i+1,j,text1,text2);

            // lets move j forward and check
            int ans2 = solve(i,j+1,text1,text2);

            ans = max(ans1,ans2);
        }
        return  dp[i][j] =  ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,text1,text2);
    }
};