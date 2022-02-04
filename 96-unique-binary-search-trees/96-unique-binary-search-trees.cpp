class Solution {
    int dp[20]={};
public:
    int numTrees(int n) {
        if(n==1 or n==0)
            return dp[n]=1;
        if(dp[n])
            return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=numTrees(i-1)*numTrees(n-i);
        }
        return dp[n]=ans;
    }
};