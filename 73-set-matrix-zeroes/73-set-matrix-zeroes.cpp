class Solution {
    void solve(vector<vector<int>>& matrix,vector<vector<bool>>& visited,int r,int c,int m,int n)
    {
        visited[r][c]=true;
        for(int x=0;x<m;x++)
        {
            visited[x][c]=true;
        }
        for(int y=0;y<n;y++)
        {
            visited[r][y]=true;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                    solve(matrix,visited,i,j,m,n);
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(visited[i][j])
                    matrix[i][j]=0;
    }
};