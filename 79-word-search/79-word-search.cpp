class Solution {
    int m,n;
    bool dfs(vector<vector<char>>& board,int i,int j,int index,string& word)
    {
        if(index == word.size()) return true; // end condition
        // boundary of matrix or char not match
        if(i < 0 or j < 0 or i >= m or j >=n or board[i][j] != word[index]) 
            return false; 
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool ans =  dfs(board, i+1, j, index+1,word) || // up
                    dfs(board, i-1, j, index+1,word) || // down
                    dfs(board, i, j-1, index+1,word) || // left
                    dfs(board, i, j+1, index+1,word);   // right
        board[i][j] = word[index]; // backtracking to OG char
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        bool ans = false;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0])
                    ans|= dfs(board,i,j,0,word);
        return ans;
        
    }
};