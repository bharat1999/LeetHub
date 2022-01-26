class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis(n,vector<int> (m,INT_MAX-10));
        // first searching for minimum distance from left and top
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                    dis[i][j] = 0;
                else
                {
                    if(i>0) // top is valid index
                        dis[i][j] = min(dis[i][j],1 + dis[i-1][j]);
                    if(j>0) // left is valid index
                        dis[i][j] = min(dis[i][j],1 + dis[i][j-1]);
                }   
            }
        }
        // than searching for minimum distance from below and right
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                    dis[i][j] = 0;
                else
                {
                    if(i+1<n) // below is valid index
                        dis[i][j] = min(dis[i][j],1 + dis[i+1][j]);
                    if(j+1<m) // right is valid index
                        dis[i][j] = min(dis[i][j],1 + dis[i][j+1]);
                }   
            }
        }
        return dis;
    }
};