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
            ans=((ans%mod)+(solve('a',l+1,n)%mod))%mod;
            ans=((ans%mod)+(solve('e',l+1,n)%mod))%mod;
            ans=((ans%mod)+(solve('i',l+1,n)%mod))%mod;
            ans=((ans%mod)+(solve('o',l+1,n)%mod))%mod;
            ans=((ans%mod)+(solve('u',l+1,n)%mod))%mod;
        }
        else
        {
            if(last=='a')
            {
                ans=((ans%mod)+(solve('e',l+1,n)%mod))%mod;
            }
            else if(last=='e')
            {
                ans=((ans%mod)+(solve('a',l+1,n)%mod))%mod;
                ans=((ans%mod)+(solve('i',l+1,n)%mod))%mod;
            }
            else if(last=='i')
            {
                ans=((ans%mod)+(solve('a',l+1,n)%mod))%mod;
                ans=((ans%mod)+(solve('e',l+1,n)%mod))%mod;
                ans=((ans%mod)+(solve('o',l+1,n)%mod))%mod;
                ans=((ans%mod)+(solve('u',l+1,n)%mod))%mod;
            }
            else if(last=='o')
            {
                ans=((ans%mod)+(solve('i',l+1,n)%mod))%mod;
                ans=((ans%mod)+(solve('u',l+1,n)%mod))%mod;
            }
            else if(last=='u')
            {
                ans=((ans%mod)+(solve('a',l+1,n)%mod))%mod;
            }
        }
        return dp[last-'a'][l] = ans;
    }
public:
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return solve('z',0,n);
    }
};