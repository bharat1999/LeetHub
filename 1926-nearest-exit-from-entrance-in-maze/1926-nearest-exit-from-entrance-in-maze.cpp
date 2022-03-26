class Solution {
    bool isValid(int i,int j,vector<vector<char>>& maze,int n,int m)
    {
        if(i<0 or j<0 or i>=n or j>=m or maze[i][j]=='+')
            return false;
        return true;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int xi = entrance[0];
        int yi = entrance[1];
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        q.push({xi,yi});
        // mark visited
        maze[xi][yi]='+';
        int level =0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto f = q.front();
                q.pop();
                int r = f.first;
                int c = f.second;
                if((r==0 or r==n-1 or c==0 or c==m-1) and (r!=xi or c!=yi))
                    return level;
                for(auto d:dir)
                {
                    int x= r+d[0];
                    int y = c+d[1];
                    if(isValid(x,y,maze,n,m))
                    {
                        q.push({x,y});
                        maze[x][y]='+';
                    }   
                }
            }
            level++;
        }
        return -1;   
    }          
};