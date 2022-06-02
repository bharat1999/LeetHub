class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int r = 0;
        int c = 0;
        vector<vector<int>> sol(m,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sol[r][c]=matrix[i][j];
                r++;
                if(r==m)
                {
                    r=0;
                    c++;
                }
            }
        }
        return sol;
    }
};