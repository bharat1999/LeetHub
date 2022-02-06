class Solution {
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m,vector<vector<bool>> &visited)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0' or visited[i][j])
            return;
        visited[i][j]=true;
        dfs(grid,i+1,j,n,m,visited);
        dfs(grid,i-1,j,n,m,visited);
        dfs(grid,i,j+1,n,m,visited);
        dfs(grid,i,j-1,n,m,visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    ans++;
                    dfs(grid,i,j,n,m,visited);
                }
            }
        }
        return ans;
    }
};