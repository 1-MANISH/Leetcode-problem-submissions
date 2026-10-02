// BRUTE FORCE -  TC  = O^3 | SC  = O(1)
// RECURSIVE   -   TC  = O^3 | SC  = O(N)

class Solution {
    bool isPal(int i,int j,string &s){
        if(i>=j)return true;
        return s[i]==s[j] and isPal(i+1,j-1,s);
    }
public:
    string longestPalindrome(string s) {
        
        int n  = s.size();
        int start = 0 , maxLen = 0;

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