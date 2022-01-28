class Solution {
public:
    int nthUglyNumber(int n) 
    {    
        int dp[n+1];
        dp[1] = 1;
        int idx2 = 1, idx3 = 1, idx5 = 1;
        for(int i=2; i<=n; i++)
        {   
            // we have to find all 3 next ugly number and take its number
            dp[i] = min(2*dp[idx2],min(3*dp[idx3],5*dp[idx5]));
            // whicherver index number become dp[i] we increment that index
            if(dp[i] == 2*dp[idx2])
                idx2++;
            if(dp[i] == 3*dp[idx3])
                idx3++;
            if(dp[i] == 5*dp[idx5])
                idx5++;
        }
        return dp[n];
        
    }
};