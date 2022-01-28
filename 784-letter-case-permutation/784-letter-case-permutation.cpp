class Solution {
    vector<string> ans;
    void solve(string s,int i)
    {
        if(s[i]==NULL)
        {
            ans.push_back(s);
            return;
        }
        if(isupper(s[i]))
        {
            solve(s,i+1);
            s[i]= tolower(s[i]);
            solve(s,i+1);
        }
        else if(islower(s[i]))
        {
            solve(s,i+1);
            s[i]= toupper(s[i]);
            solve(s,i+1);
        }
        else
            solve(s,i+1);
    }
public:
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
        return ans;
    }
};