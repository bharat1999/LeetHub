class Solution {
    int solve(string &s1,string &s2,int i,int j,int l1,int l2,vector<vector<int>> &dp)
    {
        // if both string over return 0
        if(i==l1 and j==l2)
            return dp[i][j]=0;
        // if one string over the answer will be length of remaing string
        if(i==l1)
            return dp[i][j]=l2-j;
        if(j==l2)
            return dp[i][j]=l1-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=solve(s1,s2,i+1,j+1,l1,l2,dp);
        return dp[i][j]=1+ min(solve(s1,s2,i+1,j,l1,l2,dp),solve(s1,s2,i,j+1,l1,l2,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1+1,vector<int> (l2+1,-1));
        return solve(word1,word2,0,0,l1,l2,dp);
        
    }
};