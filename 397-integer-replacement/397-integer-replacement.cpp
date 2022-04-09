class Solution {
    // to avoid memory limit
    unordered_map<long long,long long> dp;
    int solve(long long n)
    {
        if(n==1)
            return dp[n]=0;
        if(dp[n])
            return dp[n];
        if(n%2)
            return dp[n] = 1 + min(solve(n-1),solve(n+1));
        return dp[n] = 1 + solve(n/2);
    }
public:
    int integerReplacement(int n) {
        return solve(n);
    }
};