class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1)
            return {{1}};
        if(n==2)
            return {{1},{1,1}};
        vector<vector<int>> res;
        vector<vector<int>> dp(1000,vector<int> (1000));
        dp[2][1]=1;
        dp[2][2]=1;
        res.push_back({1});                
        res.push_back({1,1});
        vector<int> tmp;
        for(int i=3;i<=n;i++)
        {
            dp[i][1]=1;
            tmp.push_back(1);
            for(int j=2;j<=i-1;j++)
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                tmp.push_back(dp[i][j]);
            }
            dp[i][i]=1;
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
        
    }
};