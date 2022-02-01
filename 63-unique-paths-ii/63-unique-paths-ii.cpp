class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        obstacleGrid[0][0]=1;
        for(int i=1;i<m;i++)
        {
//prev me 1 mtlb accessible, cur me 0 mtlb no obstacle true to cur me 1 daldo yani accessible varna 0
            obstacleGrid[i][0] = (obstacleGrid[i-1][0]==1 and obstacleGrid[i][0]==0)?1:0; 
        }    
        for(int i=1;i<n;i++)
        {
            obstacleGrid[0][i] = (obstacleGrid[0][i-1]==1 and obstacleGrid[0][i]==0)?1:0; 
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1) // yani obstacle hai
                    obstacleGrid[i][j]=0; // to iska way 0 kardo
                else
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};