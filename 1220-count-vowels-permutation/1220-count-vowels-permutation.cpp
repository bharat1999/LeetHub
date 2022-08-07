class Solution {
    int mod = 1e9 + 7;
    int dp[26][20001];
    int solve(char last,int l,int n)
    {
        if(l==n)
        {
            return 1;
        }
        if(l!=0 and dp[last-'a'][l]!=-1)
            return dp[last-'a'][l];
        int ans = 0;
        if(l==0)
        {
            ans+=solve('a',l+1,n)%mod;
            ans%=mod;
            ans+=solve('e',l+1,n)%mod;
            ans%=mod;
            ans+=solve('i',l+1,n)%mod;
            ans%=mod;
            ans+=solve('o',l+1,n)%mod;
            ans%=mod;
            ans+=solve('u',l+1,n)%mod;
            ans%=mod;
        }
        else
        {
            if(last=='a')
            {
                ans+=solve('e',l+1,n)%mod;
                ans%=mod;
            }
            else if(last=='e')
            {
                ans+=solve('a',l+1,n)%mod;
                ans%=mod;
                ans+=solve('i',l+1,n)%mod;
                ans%=mod;
            }
            else if(last=='i')
            {
                ans+=solve('a',l+1,n)%mod;
                ans%=mod;
                ans+=solve('e',l+1,n)%mod;
                ans%=mod;
                ans+=solve('o',l+1,n)%mod;
                ans%=mod;
                ans+=solve('u',l+1,n)%mod;
                ans%=mod;
            }
            else if(last=='o')
            {
                ans+=solve('i',l+1,n)%mod;
                ans%=mod;
                ans+=solve('u',l+1,n)%mod;
                ans%=mod;
            }
            else if(last=='u')
            {
                ans+=solve('a',l+1,n)%mod;
                ans%=mod;
            }
        }
        return dp[last-'a'][l] = ans%mod;
    }
public:
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return solve('z',0,n);
    }
};