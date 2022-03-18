class Solution {
    void check(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,bool& flag)
    {
        if(i<0 or j<0 or i>=grid2.size() or j>=grid2[0].size() or grid2[i][j]==0)
            return;
        // if island present in grid2 but not in grid 1 return false
        if(grid2[i][j]==1 and grid1[i][j]==0)
        {
            flag = false;
            return;
        }
        grid1[i][j]=0;
        grid2[i][j]=0;
        check(grid1,grid2,i+1,j,flag);
        check(grid1,grid2,i,j+1,flag); 
        check(grid1,grid2,i-1,j,flag);
        check(grid1,grid2,i,j-1,flag);
    }
    public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        bool flag;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {flag = true;
                if(grid2[i][j]==1)
                {
                    check(grid1,grid2,i,j,flag);
                    if(flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};