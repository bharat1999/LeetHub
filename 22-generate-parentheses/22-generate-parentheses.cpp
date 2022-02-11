class Solution {
public:
    vector<string> ans;
    void solve(string s,int n,int open,int close)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return;
        }
        // insert (
        if(open<n)
        {
            s.push_back('(');
            solve(s,n,open+1,close);
            s.pop_back();
        }
        // insert )
        if(close<open)
        {  
            s.push_back(')');
            solve(s,n,open,close+1);
            s.pop_back();
        }   
        
    }
    vector<string> generateParenthesis(int n) 
    {
        string s="";
        solve(s,n,0,0);
        return ans;
    }
};