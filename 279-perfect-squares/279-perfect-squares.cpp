class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        //base case
        dp[0]=0;
        int count = 1;
        while(count*count <= n) 
        {
            int sq = count*count;
            // dp[i] will be no of perfect suqares required for i -sq number +1
            for(int i = sq; i <=n; i++) 
                dp[i] = min(dp[i-sq] + 1,dp[i]);
            count++;
        }
    return dp[n];
    }
};