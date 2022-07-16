class Solution {
    long long mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int dfs(int &m,int &n,int i,int j,int moveLeft)
    {
        if(i<0 or j<0 or i>=m or j>=n)
            return 1;
        if(moveLeft==0)
            return 0;
        if(dp[i][j][moveLeft]!=-1)
            return dp[i][j][moveLeft];
        return dp[i][j][moveLeft] = (dfs(m,n,i+1,j,moveLeft-1)%mod +
                                    dfs(m,n,i,j+1,moveLeft-1)%mod +
                                    dfs(m,n,i-1,j,moveLeft-1)%mod +
                                    dfs(m,n,i,j-1,moveLeft-1)%mod)%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m+1,vector<vector<int>> (n+1,vector<int> (maxMove+1,-1)));
        return dfs(m,n,startRow,startColumn,maxMove);
    }
};