class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        string ans1="",ans2="";
        for(auto x:s)
        {
            if(x=='#')
            {
                if(!s1.empty())
                    s1.pop();
            }
            else
                s1.push(x);
                
        }
        for(auto x:t)
        {
            if(x=='#')
            {
                if(!s2.empty())
                    s2.pop();
            }
            else
                s2.push(x);
        }
        while(!s1.empty())
        {
            ans1.push_back(s1.top());
            s1.pop();
        }
        while(!s2.empty())
        {
            ans2.push_back(s2.top());
            s2.pop();
        }
        return ans1==ans2;
    }
};