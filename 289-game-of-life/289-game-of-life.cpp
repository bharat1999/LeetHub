class Solution {
   vector<vector<int>> dirs = {
        {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1,-1} 
    };

    bool isValid(vector<vector<int>>& board, int r, int c) 
    {
        int aliveCount = 0;
        for(auto& dir : dirs) 
        {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr < 0 or nr >= board.size()) continue;
            if(nc < 0 or nc >= board[r].size()) continue;
            
            aliveCount += board[nr][nc];
        }
        if(board[r][c]==1)
        {
            if(aliveCount>=2 and aliveCount<=3)
                return true;
            return false;
        }
        else
        {
            if(aliveCount==3)
                return true;
            return false;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> state(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                state[i][j] = isValid(board,i,j);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(state[i][j])
                    board[i][j]=1;
                else
                    board[i][j]=0;
            }
        }
    }
};