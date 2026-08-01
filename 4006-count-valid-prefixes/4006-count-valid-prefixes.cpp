class Solution {
public:
    int countValidPrefixes(string s) {
        int zeros = 0 , ones = 0;
        int ans = 0;
        for(auto ch:s){
            if(ch=='0')zeros++;
            else ones++;

            if(abs(zeros-ones)<=1)ans++;
        }
        return ans;
    }
};