class Solution
{
    unordered_map<char,int> mapping= {
        {'(',1},{')',-1},
        {'[',2},{']',-2},
        {'{',3},{'}',-3},
    };
    public:
        bool isValid(string s)
        {
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                if (mapping[s[i]]>0) st.push(mapping[s[i]]);
                else
                {
                    if (st.size() == 0) return false;
                    else if (st.top()+mapping[s[i]]!=0) return false;
                    st.pop();
                }
            }
            return st.size() == 0;
        }
};