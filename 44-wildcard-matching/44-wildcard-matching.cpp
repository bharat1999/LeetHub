class Solution {
    vector<vector<int>> dp;
public:
    bool solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        
        if(i<0 and j<0)
            return true;
        if(j<0)
            return false;
        if(i<0)
        {
            for(int x=j;x>=0;x--)
            {
                if(s2[x] != '*') 
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1) 
            return dp[i][j];        
        if(s1[i] == s2[j] or s2[j] == '?') 
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        else if(s2[j] == '*') 
            return dp[i][j] = solve(i,j-1,s1,s2,dp) or solve(i-1,j,s1,s2,dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};