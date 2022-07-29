class Solution {
    string hash(string s)
    {
        string ans="";
        unordered_map<char,int> idx;
        for(int i=0,n=s.size();i<n;i++)
        {
            if(idx.count(s[i]))
                ans.push_back(idx[s[i]]+'0');
            else
            {
                ans.push_back(i+'0');
                idx[s[i]] = i;
            }
        }
        return ans;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string pat = hash(pattern);
        for(auto x:words)
        {
            if(hash(x)==pat)
                ans.push_back(x);
        }
        return ans;
    }
};