class Solution {
    bool isValid(string &s)
    {
        if(s[0]=='0')
            return false;
        if(s[0]>'2')
            return false;
        if(s[0]=='2' and s[1]>'6')
            return false;
        return true;
    }
    int solve(string &s,int i,int n,vector<int> &dp)
    {
        // string decoded so return 1 as we got one possible answer
        if(i==n)
            return dp[i]=1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='0')
            return dp[i]=0;
        int ans=0;
        //taking single character for all from i
        ans+=solve(s,i+1,n,dp);
        //taking 2 character if valid
        if(i<n-1)
        {
            string tmp = s.substr(i,2);
            if(isValid(tmp))
                ans+= solve(s,i+2,n,dp);
        }
        return dp[i]=ans;
        
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1); // dp[i] means number of ways starting from index i
        return solve(s,0,n,dp);
    }
};