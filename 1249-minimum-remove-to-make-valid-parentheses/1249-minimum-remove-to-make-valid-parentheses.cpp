class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int close = 0;
        int open = 0;
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]==')')
            {
                if(close>=open)
                    continue;
                else
                    close++;    
            }
            else if(s[i]=='(')
                open++;
            ans.push_back(s[i]);
        }
        if(open==close)
            return ans;
        string res="";
        for(int n=ans.size(),i=n-1;i>=0;i--)
        {
            if(ans[i]=='(')
            {
                if(open!=close)
                {
                    open--;
                    continue;
                }
            }
            res.push_back(ans[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};