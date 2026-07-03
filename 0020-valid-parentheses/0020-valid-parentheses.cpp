class Solution
{
    private:
        bool isOpening(char & ch)
        {
            if (ch == '(' || ch == '[' || ch == '{') return true;
            return false;
        }
    bool isMatched(char &top, char &current)
    {
        if (top == '(' && current == ')') return true;
        if (top == '[' && current == ']') return true;
        if (top == '{' && current == '}') return true;
        return false;
    }
    public:
        bool isValid(string s)
        {
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                if (isOpening(s[i])) st.push(s[i]);
                else
                {
                    if (st.size() == 0) return false;
                    else if (!isMatched(st.top(), s[i])) return false;
                    st.pop();
                }
            }
            return st.size() == 0;
        }
};