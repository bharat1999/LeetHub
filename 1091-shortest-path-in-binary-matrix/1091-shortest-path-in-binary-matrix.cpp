class Solution {
    bool isValid(vector<vector<int>>&grid,int i,int j,int n,vector<vector<bool>>&visited)
    {
        if(i<0 or j<0 or i>=n or j>=n or grid[i][j]==1 or visited[i][j])
            return false;
        return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<vector<int>> directions = {
            {1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}
        };
        if(grid[0][0]==1 or grid[size-1][size-1]==1)
            return -1;
        vector<vector<bool>> visited(size,vector<bool> (size,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=true;
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int n = q.size();
            while(n--)
            {
                auto front = q.front();
                q.pop();
                int r = front.first;
                int c = front.second;
                cout<<r<<" "<<c<<endl;
                if(r==size-1 and c==size-1)
                    return ans;
                // visited all non visited directions in queue
                for(auto d:directions)
                {
                    int nr = r+d[0];
                    int nc = c+d[1];
                    if(isValid(grid,nr,nc,size,visited))
                    {
                        q.push({nr,nc});
                        visited[nr][nc]=true;
                    }
                }
            }
        }
        return -1;
    }
};