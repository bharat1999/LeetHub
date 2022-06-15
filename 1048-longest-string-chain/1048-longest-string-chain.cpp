class Solution {
    static bool cmp(string &a,string &b)
    {
        return a.size()<b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),cmp);
        int ans = 1;
        for(auto x:words)
        {
            // add x in dp
            dp[x] = 1;
            for(int i=0,n=x.size();i<n;i++)
            {
                // make new string without ith char
                string temp = x.substr(0,i)+x.substr(i+1);
                dp[x] = max(dp[x],dp[temp]+1);
            }
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};