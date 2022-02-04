class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1]=1;
        int idx2 =1 ,idx3=1,idx5 =1;
        for(int i=2;i<=n;i++)
        {
            long long val2 = 2*dp[idx2];
            long long val3 = 3*dp[idx3];
            long long val5 = 5*dp[idx5];
            long long mi = min(val2,min(val3,val5));
            dp[i]=mi;
            if(mi == val2)
                idx2++;
            if(mi == val3)
                idx3++;
            if(mi==val5)
                idx5++;
        }
        return dp[n];
    }
};