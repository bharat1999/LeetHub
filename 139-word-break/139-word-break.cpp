class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(n==0) 
            return false;
        unordered_map<string,bool> mp;
        for(auto x:wordDict)
            mp[x]=true;
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int longestString = INT_MIN;
        for(auto x:wordDict)
            longestString = max(longestString,(int)x.size());
        
        for(int i=1;i<=n;i++) // This will be the ending index of substring
        {
            // we will only find substrings,whose length <= longestString to avoid extra iteration
            for(int j=max(0,i-longestString);j<i;j++)
            {
                // if their is a valid segment ending here than only we can check another from here
                // we are checking j bcz j is ending of valid and in substr end in exclusive
                // if their is no valid segment before j than we cannot find another after that
                if(dp[j]) 
                {
                    string word = s.substr(j,i-j);
                    if(mp[word]==true)
                    {
                    //means we found a valid segment which ends at i & we have to find after that
                        //(bcz ending index is exclusive in substr)
                        dp[i]=true; 
                        break; //next i
                    }
                }
            }
        }
        
        return dp[n];
    }
};