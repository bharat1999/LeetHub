class Solution {
    vector<long long> dp;
    long long mod = 1e9+7;
    long long fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 or n == 2)
            return dp[n] = 1;
        if (dp[n]!=-1)
            return dp[n];
    
        long long k = (n & 1)? (n+1)/2 : n/2;
        return dp[n] = (n & 1)? ((fib(k)%mod)*(fib(k)%mod)%mod + ((fib(k-1)%mod)*(fib(k-1)%mod))%mod)
           : ((2*fib(k-1) + fib(k))%mod)*(fib(k)%mod)%mod;
 
}
public:
    int countHousePlacements(int n) {
        dp.resize(n+3,-1);
        long long ans = fib(n+2);
        cout<<ans;
        
        long long sol =  ((ans%mod)*(ans%mod))%mod;
        return (int)sol;
    }
};