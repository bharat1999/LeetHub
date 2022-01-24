class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s)
        {
            if(x=='(' or x=='[' or x=='{')
                st.push(x);
            else
            {
                if(st.empty())
                    return false;
                else if(x==']' and st.top()=='[')
                    st.pop();
                else if(x=='}' and st.top()=='{')
                    st.pop();
                else if(x==')' and st.top()=='(')
                    st.pop();
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};