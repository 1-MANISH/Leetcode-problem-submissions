// BRUTE FORCE -  TC  = O^3 | SC  = O(1)
// RECURSIVE   -   TC  = O^3 | SC  = O(N)
// DP          - TC = O(n^2) amortized | SC = O(N*N)
// DP + TABULATIOn -  TC (O^2) | SC = O(N*N)
class Solution {

public:
    string longestPalindrome(string s) {
        
        int n  = s.size();
        int start = 0 , maxLen = 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int i = n ; i >= 0 ;i--){
            for(int j = n ; j >=0 ; j--){
                int &ans = dp[i][j];
                if(i>=j){
                    ans=true;
                    continue;
                }
                ans = ( s[i]==s[j] and dp[i+1][j-1]);
            }
        }
        for(int i  = 0 ; i < n  ; i++){
            for(int j = i; j<n ; j++){
                if(dp[i][j]){
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