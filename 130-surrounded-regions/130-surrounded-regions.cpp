class Solution {
    void DFS(vector<vector<char>>& board,int i,int j,int m,int n)
    {
        if(i<0 or j<0 or i>=m or j>=n or board[i][j]!='O')
            return;
        board[i][j]='?';
        DFS(board,i+1,j,m,n);
        DFS(board,i,j+1,m,n);
        DFS(board,i-1,j,m,n);
        DFS(board,i,j-1,m,n);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        //checking first row
        for(int j=0;j<n;j++)
            if(board[0][j]=='O')
                DFS(board,0,j,m,n);
        //checking first col
        for(int i=0;i<m;i++)
            if(board[i][0]=='O')
                DFS(board,i,0,m,n);
        //checking last row
        for(int j=0;j<n;j++)
            if(board[m-1][j]=='O')
                DFS(board,m-1,j,m,n);
        //checking last col
        for(int i=0;i<m;i++)
            if(board[i][n-1]=='O')
                DFS(board,i,n-1,m,n);
        // Now flip possible characters
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
        //Now change border value ? to O
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='?')
                    board[i][j]='O';
    }
};