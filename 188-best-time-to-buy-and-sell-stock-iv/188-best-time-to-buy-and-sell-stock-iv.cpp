class Solution {
    // 1000 = max stocks 100= max transactions 2 = as buy have 2 states false or true
    int dp[1000][101][2];
    int t;
    int solve(vector<int>&p,int i,int c,bool buy)
    {
        if(i>=p.size() or c>=t)
            return 0;
        if(dp[i][c][buy]!=-1)
            return dp[i][c][buy];
        // if we need to buy than 2 possibility either buy or skip
        // decreases p[i] cause on buy we are spending money
        // we will not decrease k as transaction will complete on sell
        if(buy)
            dp[i][c][buy] = max(solve(p,i+1,c,buy),-p[i] + solve(p,i+1,c,!buy));
        // on sell we add p[i] cause on sell we get that much money and decrease k also
        else if(!buy)
            dp[i][c][buy] = max(solve(p,i+1,c,buy),p[i]+solve(p,i+1,c+1,!buy));
        return dp[i][c][buy];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // means we cannot do k transactions
        t = k;
        if (2 * k > prices.size()) 
        {
            int res = 0;
            for (int i = 1; i < prices.size(); i++) 
                res += max(0, prices[i] - prices[i - 1]);
            return res;
        }
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,1);
    }
};