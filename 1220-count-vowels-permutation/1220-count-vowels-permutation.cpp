class Solution {
    int mod = 1e9 + 7;
    // considering a = 0 till u = 4
    int dp[5][20001];
    int solve(int last,int l,int n)
    {
        if(l==n)
        {
            return 1;
        }
        if(l!=0 and dp[last][l]!=-1)
            return dp[last][l];
        int ans = 0;
        for(int i=0;i<5;i++)
        {
            // is last was a and current is e
            if(last==0 and i==1)
                ans=((ans%mod) + (solve(i,l+1,n)%mod))%mod;
            // last was e and current is a or i
            else if(last==1 and (i==0 or i==2))
                ans=((ans%mod) + (solve(i,l+1,n)%mod))%mod;
            // last was i and current is not i
            else if(last==2 and i!=2)
                ans=((ans%mod) + (solve(i,l+1,n)%mod))%mod;
            // last is o and current is i or u
            else if(last==3 and (i==2 or i==4))
                ans=((ans%mod) + (solve(i,l+1,n)%mod))%mod;
            else if(last==4 and i==0)                
                ans=((ans%mod) + (solve(i,l+1,n)%mod))%mod;
        }
        return dp[last][l] = ans%mod;
    }
public:
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<5;i++)
            ans = ((ans%mod) + (solve(i,1,n)%mod))%mod;
        return ans;
    }
};