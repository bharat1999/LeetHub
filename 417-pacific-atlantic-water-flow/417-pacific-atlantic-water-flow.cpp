class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, int j, int prev, vector<vector<bool>>& ocean)
    {
        if(i < 0 or i >= mat.size() or j < 0 or j >= mat[0].size())
            return;
// In og problem we will only go to equal or lesser height so in inverse we go only to higher
        if(mat[i][j] < prev or ocean[i][j])
            return;
        
        ocean[i][j] = true;
        dfs(mat, i - 1, j, mat[i][j], ocean);
        dfs(mat, i + 1, j, mat[i][j], ocean);
        dfs(mat, i, j - 1, mat[i][j], ocean);
        dfs(mat, i, j + 1, mat[i][j], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++)
        {
            if(!pacific[i][0])
                dfs(mat, i, 0, INT_MIN, pacific);
        }
        
        for(int j = 0; j < m; j++)
        {
            if(!pacific[0][j])
                dfs(mat, 0, j, INT_MIN, pacific);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!atlantic[i][m - 1])
                dfs(mat, i, m - 1, INT_MIN, atlantic);
        }
        
        for(int j = 0; j < m; j++)
        {
            if(!atlantic[n - 1][j])
                dfs(mat, n - 1, j, INT_MIN, atlantic);
        }
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] and atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        
        return res;
    }
};