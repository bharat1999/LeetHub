class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> dp;
    int n,m;
    bool isValid(int x, int y){
        if(x<0 or y<0 or x>=n or y>=m) return false;
        return true;
    }
    
    int solve(vector<vector<int>>& matrix, int x, int y)
    {    
        if(dp[x][y] != -1) 
            return dp[x][y];
        int cur = 0;
        for(auto k:dir)
        {
            int x1 = x+k[0], y1=y+k[1];
            if(x1>=0 and y1>=0 and x1<n and y1<m and matrix[x1][y1] > matrix[x][y])
            {
                cur = max(cur, solve(matrix,x1,y1));
            }
        }
        return dp[x][y] = 1 + cur;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        n = matrix.size(), m = matrix[0].size();
        dp.resize(n,vector<int> (m,-1));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                ans = max(ans, solve(matrix,i,j));
            }
        }
        return ans;
    }
};