// BRUTE FORCE -  TC  = O^3 | SC  = O(1)
// RECURSIVE   -   TC  = O^3 | SC  = O(N)
// DP          - TC = O(n^2) amortized | SC = O(N)

const int N = 1e3;
int dp[N][N];// 0,1,-1 (not calculated yet)
class Solution {
    bool isPal(int i,int j,string &s){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = ( s[i]==s[j] and isPal(i+1,j-1,s));
    }
public:
    string longestPalindrome(string s) {
        
        int n  = s.size();
        int start = 0 , maxLen = 0;
        memset(dp,-1,sizeof dp);
        for(int i  = 0 ; i < n  ; i++){
            for(int j = i; j<n ; j++){
                if(isPal(i,j,s)){
                    if(j-i+1 > maxLen){
                        start = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }

        return s.substr(start,maxLen);
    }
};