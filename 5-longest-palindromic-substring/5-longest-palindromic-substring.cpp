class Solution {
    bool isPallindrome(string s)
    {
        int i=0;
        int e=s.size()-1;
        while(i<e)
        {
            if(s[i]!=s[e])
                return false;
            i++;
            e--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        // as string starting and ending at same index is always //pallindrome
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        string ans="";
        // single element will always be the answer
        ans.push_back(s[0]);
        int maxLen = 1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 or dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        if(j-i+1>maxLen)
                        {
                            maxLen = j-i+1;
                            ans = s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};