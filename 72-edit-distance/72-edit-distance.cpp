class Solution {
    public:
        int minDistance(string s1, string s2) 
        {
            int m=s1.size();
            int n=s2.size();
            vector<vector<int>> dp(m+1,vector<int> (n+1));
            for(int i=m; i>=0; i--) 
            {
		        for(int j=n; j>=0; j--) 
                {
			        if(i == m && j == n) 
				        dp[i][j] = 0;
			        else  if(i == m) 
				        dp[i][j] = n-j;
			        else if(j == n) 
				        dp[i][j] = m-i;
			        else 
                    {
				        dp[i][j] = min(1+dp[i][j+1],
		                   min(1+dp[i+1][j],
		                       int(s1[i] != s2[j])+dp[i+1][j+1]));
			        }
		        }
	        }
	        return dp[0][0];
        }
};