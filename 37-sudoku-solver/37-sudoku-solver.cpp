class Solution {
    bool isValid(vector<vector<char>> &board,int i,int j,char no)
    {
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==no or board[k][j]==no)
                return false;
        }
        int sr=(i/3)*3;                // this will give starting row of small part
        int sc=(j/3)*3;                // this will give starting col of small part
        for(int x=sr;x<sr+3;x++)
        {
            for(int y=sc;y<sc+3;y++)
            {
                if(board[x][y]==no)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board,int i,int j)
    {
        // whole soduku solved
        if(i==9)
            return true;
        // one row solved so move to next row
        if(j==9)
           return solve(board,i+1,0);
        if(board[i][j]!='.')
            return solve(board,i,j+1);
        else
        {
            for(char c='1';c<='9';c++)
            {
                if(isValid(board,i,j,c))
                {
                    board[i][j]=c;
                    if(solve(board,i,j+1))
                        return true; 
                    board[i][j]='.';
                }    
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};