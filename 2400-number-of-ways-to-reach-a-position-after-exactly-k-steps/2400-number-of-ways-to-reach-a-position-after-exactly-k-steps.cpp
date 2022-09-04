class Solution {
    int m = 1e9+7;
    int dp[20001][1001];
    long long solve(int s,int e,int k)
    {
        if(s==e and k==0)
            return 1;
        if(k<0)
            return 0;
        if(dp[s][k]!=-1)
            return dp[s][k];
        return dp[s][k] = (solve(s-1,e,k-1)%m + solve(s+1,e,k-1)%m)%m;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
       // + 1000 so that can't go to -
        return solve(startPos+1000,endPos+1000,k)%m;
    }
};