class NumMatrix {
    vector<vector<int>> prefix;
    int n,m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        prefix.resize(n,vector<int> (m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j==0)
                    prefix[i][j] = matrix[i][j];
                else if(i==0)
                    prefix[i][j] = prefix[i][j-1] + matrix[i][j];
                else if(j==0)
                    prefix[i][j] = prefix[i-1][j] + matrix[i][j];
                else
                    prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int topPrefix = (row1-1>=0)?prefix[row1-1][col2]:0;
        int leftPrefix = (col1-1>=0)?prefix[row2][col1-1]:0;
        int topleftPrefix = ((row1-1>=0 and col1-1>=0)?prefix[row1-1][col1-1]:0);
        int bottomrightPrefix = prefix[row2][col2];
        return bottomrightPrefix - topPrefix - leftPrefix + topleftPrefix;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */