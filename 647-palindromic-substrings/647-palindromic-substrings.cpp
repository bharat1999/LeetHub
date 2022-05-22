class Solution {
    vector<vector<int>> dp;
    bool check(int i,int j,string s)
    {
        if(i==j)
            return dp[i][j] = true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j-i==1)
            return dp[i][j]=(s[i]==s[j]?1:0);
        return dp[i][j] = (s[i]==s[j]?check(i+1,j-1,s):0);
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        dp.resize(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
            {
                if(check(i,j,s))
                    ans++;
            }
        }
        return ans;
    }
};