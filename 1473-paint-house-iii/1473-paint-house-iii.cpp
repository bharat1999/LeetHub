class Solution {
    int maxCost = 1000001;
    // [houses Idx][color][neighbourhoods till ith index]
    int dp[100][22][101];
    int solve(vector<int> &houses,vector<vector<int>> &cost,int i,int target,int prevColor,int hoodCount)
    {
        if(target<hoodCount)
            return maxCost;
        if(i==houses.size())
        {
            return target==hoodCount?0:maxCost;
        }
        if(dp[i][prevColor][hoodCount]!=-1)
            return dp[i][prevColor][hoodCount];
        int minCost = maxCost;
        if(houses[i]!=0)
        {
            int newHoodCount = hoodCount+ (houses[i]==prevColor?0:1);
            minCost = solve(houses,cost,i+1,target,houses[i],newHoodCount);
        }
        else
        {
            for(int color=1,n=cost[0].size();color<=n;color++)
            {
                int newHoodCount = hoodCount+ (color==prevColor?0:1);
                int curCost = cost[i][color-1]+solve(houses,cost,i+1,target,color,newHoodCount);
                minCost = min(minCost,curCost);
            }
        }
        return dp[i][prevColor][hoodCount] = minCost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(houses,cost,0,target,n+1,0);
        return ans==maxCost?-1:ans;
    }
};