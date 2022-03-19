class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        int count=0;
        while(!q.empty())
        {
            count++;    
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;   
                q.pop();
                
				//if we find a 0, we mark it visited using 1 and push it in the queue for the next multisource bfs call
				
                if(x+1<grid.size() and grid[x+1][y]==0)
                {
                    q.push({x+1,y});
                    grid[x+1][y]=1;
                }
                if(x-1>=0 and grid[x-1][y]==0)
                {
                    q.push({x-1,y});
                    grid[x-1][y]=1;
                }
                if(y+1<grid[0].size() and grid[x][y+1]==0)
                {
                     q.push({x,y+1});
                     grid[x][y+1]=1;
                }                   
                if(y-1>=0 and grid[x][y-1]==0)
                {
                    q.push({x,y-1});
                    grid[x][y-1]=1;
                }
            }
            
        }
        
        return count>1?count-1:-1;
        
    }
};