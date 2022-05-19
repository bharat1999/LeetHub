class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int dp[201][201];
    int n,m;
    bool isValid(int x, int y){
        if(x<0 or y<0 or x>=n or y>=m) return false;
        return true;
    }
    
    int solve(vector<vector<int>>& matrix, int x, int y){
        
        if(dp[x][y] != -1) 
            return dp[x][y];
        int cur = 1;
        for(auto k:dir)
        {
            int x1 = x+k[0], y1=y+k[1];
            if(isValid(x1,y1) and matrix[x1][y1] > matrix[x][y])
            {
                cur = max(cur, 1 + solve(matrix,x1,y1));
            }
        }
        return dp[x][y] = cur;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                ans = max(ans, solve(matrix,i,j));
            }
        }
        return ans;
    }
};