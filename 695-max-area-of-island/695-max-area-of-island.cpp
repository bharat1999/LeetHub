class Solution {
    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<bool>>& visited)
    {
       
        visited[i][j]=true;
        int up = 0,right = 0,down = 0,left = 0;
        if(i-1>=0 and grid[i-1][j]==1 and !visited[i-1][j])
            up = 1 + dfs(grid,i-1,j,m,n,visited);
        if(j+1<n and grid[i][j+1]==1 and !visited[i][j+1])
            right = 1 + dfs(grid,i,j+1,m,n,visited);
        if(i+1<m and grid[i+1][j]==1 and !visited[i+1][j])
            down = 1 + dfs(grid,i+1,j,m,n,visited);
        if(j-1>=0 and grid[i][j-1]==1 and !visited[i][j-1])
            left = 1 + dfs(grid,i,j-1,m,n,visited);
        return  up + right + down + left;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m,vector<bool> (n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 and !visited[i][j])
                    ans = max(ans,1+dfs(grid,i,j,m,n,visited));
            }
        }
        return ans;
    }
};