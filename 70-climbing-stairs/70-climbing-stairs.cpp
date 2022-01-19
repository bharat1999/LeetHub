class Solution {
    
    int stairs(int n,int *dp)
    {
        if(n==1 or n==2)
        {
            return dp[n]=n;
        }
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=stairs(n-1,dp)+stairs(n-2,dp);
    }    
public:
    int climbStairs(int n) {
        int dp[46];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
            dp[i]= dp[i-1] + dp[i-2]; // way to reach n form n-1 and n-2 th stair
        return dp[n];
    }
};