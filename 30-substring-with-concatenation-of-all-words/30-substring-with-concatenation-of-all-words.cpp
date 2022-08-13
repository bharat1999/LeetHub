class Solution {
    bool isValid(string s,unordered_map<string,int> mp,int len)
    {
        int i=0;
        int n = s.size();
        while(i<n)
        {
            string temp = s.substr(i,len);
            if(mp.find(temp)!=mp.end())
            {
                if(--mp[temp]==-1)
                    return false;
            }
            else
                return false;
            i+=len;
        }
        return true;
    }
public:
    vector<int> findSubstring(string a, vector<string>& words) {
        int s = words[0].size();
        int k = s*words.size();
        int n = a.size();
        unordered_map<string,int> mp;
        vector<int> ans;
        for(auto x:words)
            mp[x]++;
        for(int i=0;i<=n-k;i++)
        {
            string t = a.substr(i,k);
            if(isValid(t,mp,s))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};