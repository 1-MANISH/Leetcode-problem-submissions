const int N = 5e2;
int dp[N][N];

class Solution {
public:
    int solve(int i,int j , string &word1,string &word2){
        // base case

        if(i==word1.size()){
            return word2.size()-j;
        }

        if(j==word2.size()){
            return word1.size()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        // if both character already equals
        if(word1[i]==word2[j]){
            ans  = solve(i+1,j+1,word1,word2);
        }else{
            // can do replace , insert and remove 

            // replace
            int ans1 = 1 + solve(i+1,j+1,word1,word2);

            // insert at i or remove at j
            int ans2 = 1 + solve(i,j+1,word1,word2);

            // insert at j or remove at i
            int ans3 = 1 + solve(i+1,j,word1,word2);

            ans = min(ans1,min(ans2,ans3));
        }

        return dp[i][j] =  ans;

    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,word1,word2);
    }
};