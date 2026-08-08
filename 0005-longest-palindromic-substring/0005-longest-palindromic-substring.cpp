class Solution {
public:

   
    string longestPalindrome(string s) {
        
        // ODD & Even Length Wala method->

        int  n = s.size();
        int mxLen = INT_MIN;
        int start = 0, end = 0;

        // for odd length
        int i = 0 , j = 0;
        while(i < n && j< n)
        {
            if(s[i] == s[j])
            {// matches

                int currLen = j-i+1;
                if(currLen > mxLen)
                {// update len if currLen>prevLen
                    mxLen = currLen;
                    start = i;
                    end = j;
                }
                int x = i-1 , y = j+1;
                while(x >= 0 && y < n)
                {
                    if(s[x] == s[y])
                    {//macthes

                        int currLen = y-x+1;
                        if(currLen > mxLen)
                        {//update len
                            mxLen = currLen;
                            start = x;
                            end = y;
                        }
                        x--;
                        y++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            // next case
            i++;
            j++;
        }

        // for Even length
        i = 0 , j = 1;
        while(i < n && j < n)
        {
            if(s[i] == s[j])
            {//maches
                int currLen = j-i+1;
                if(currLen > mxLen)
                {//update len
                    mxLen = currLen;
                    start = i;
                    end = j;
                }

                int x = i-1 , y = j+1;

                while(x >= 0 && y < n)
                {
                    if(s[x] == s[y])
                    {//matches
                        int currLen = y-x+1;
                        if(currLen>mxLen)
                        {
                            mxLen = currLen;
                            start = x;
                            end = y;
                        }
                        x--;
                        y++;
                    }
                    else
                    {
                        break;
                    }
                }

            }
            // next case
            i++;
            j++;
        }

        string rejult = s.substr(start,mxLen);
        return rejult;
    }
};