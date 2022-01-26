class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(n==0) 
            return false;
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int longestString = INT_MIN;
        for(auto x:wordDict)
            longestString = max(longestString,(int)x.size());
        
        for(int i=1;i<=n;i++) // finding all substrings
        {
            // we will only find substrings,whose length <= longestString to avoid extra iteration
            for(int j=max(0,i-longestString);j<i;j++)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),word)!= wordDict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[n];
    }
};