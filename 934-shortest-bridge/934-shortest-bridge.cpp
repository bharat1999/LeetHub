class Solution {
    vector<vector<int>> dir = {{0, -1}, {0 , 1}, {1, 0}, {-1, 0}};
    queue<pair<int,int>> q;
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c,int n,int m) 
    {
        if(r<0 or r>=n or c<0 or c>=m or visited[r][c] or !grid[r][c]) 
            return;
        visited[r][c] = true;
        q.push({ r, c });
        for (auto d:dir)
            dfs(grid, visited, r +d[0] , c + d[1],n,m);
    }
    bool isValid(int x,int y,int n,int m,vector<vector<bool>>& visited)
    {
        if(x >=0 and x<n and y>= 0 and y<m and !visited[x][y])
            return true;
        return false;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool foundIsland = false;
        
        for (int i = 0; i < n; i++) {
            if (foundIsland) 
                break;
            for (int j = 0; j <n; j++) {
                if (grid[i][j]) {
                    dfs(grid, visited, i, j,n,m);
                    foundIsland = true;
                    break;
                }
            }
        }
        
        int distance = 0;
        while (!q.empty()) 
        {
            auto size = q.size();
            while (size--) 
            {
                auto f = q.front();
                q.pop();
                for (auto d:dir) 
                {
                    int x = f.first + d[0];
                    int y = f.second + d[1];
                    if (isValid(x,y,n,m,visited)) {
                        if (grid[x][y])
                            return distance;
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
    
    
};