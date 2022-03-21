class Solution {
    pair<int, int> adj[4] = {{0, -1}, {0 , 1}, {1, 0}, {-1, 0}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> myQ;
        bool foundIsland = false;
        
        for (int i = 0; i < grid.size(); i++) {
            if (foundIsland) 
                break;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    traceIsland(grid, visited, myQ, i, j);
                    foundIsland = true;
                    break;
                }
            }
        }
        
        int distance = 0;
        while (!myQ.empty()) {
            auto size = myQ.size();
            while (size > 0) {
                auto frnt = myQ.front();
                myQ.pop();
                for (int i = 0; i < 4; i++) {
                    int x = frnt.first + adj[i].first;
                    int y = frnt.second + adj[i].second;
                    if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and !visited[x][y]) {
                        if (grid[x][y])
                            return distance;
                        visited[x][y] = true;
                        myQ.push({x, y});
                    }
                }
                size--;
            }
            distance++;
        }
        return distance;
    }
    
    void traceIsland(vector<vector<int>> &grid, vector<vector<bool>> &visited, queue<pair<int, int>> &myQ, int r, int c) {
        if (r < 0 or r >=grid.size() or c < 0 or c >= grid[0].size() or visited[r][c] or !grid[r][c])  
            return;
        visited[r][c] = true;
        myQ.push({ r, c });
        for (int i = 0; i < 4; i++)
            traceIsland(grid, visited, myQ, r + adj[i].first, c + adj[i].second);
    }
};