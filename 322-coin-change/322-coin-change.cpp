class Solution {
public:
    int mincoin(vector<int> a,int n,int m)
    {
        if(n==0)
            return 0;  
        long long int dp[m][n+1];
        // amount is 0 so 0 coins required
        for(int i=0;i<m;i++)
            dp[i][0]=0;
        for(int i=0;i<m;i++)
        {
             for(int j=1;j<=n;j++)
            {
                long long int x=INT_MAX,y=INT_MAX;
                x = i-1>=0 ? dp[i-1][j]:INT_MAX; // ek baar coin nhi lia
                y = j-a[i]>=0?1+dp[i][j-a[i]]:INT_MAX; // ek baar le lia
                dp[i][j]=min(x,y);   
            }
        }   
        return dp[m-1][n]; // ek baad last wala lege ek baar nahi
    }
    int coinChange(vector<int>& coins, int amount) {
        long long int ans =mincoin(coins,amount,coins.size());
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};