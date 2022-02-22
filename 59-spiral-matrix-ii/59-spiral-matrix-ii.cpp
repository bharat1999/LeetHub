class Solution {
    public:
    vector<vector<int>> generateMatrix(int n) {
        // Declaration
        vector<vector<int>> matrix(n,vector<int> (n));
        
        // Edge Case
        if (n == 0) {
            return matrix;
        }
        
        // Normal Case
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n-1;
        int num = 1;
        
        while (rowStart <= rowEnd and colStart <= colEnd) 
        {
            // going left to right
            for (int i = colStart; i <= colEnd; i ++) 
                matrix[rowStart][i] = num ++;
            // updating starting row as current startRow fully filled
            rowStart ++;
            
            // going top to bottom
            for (int i = rowStart; i <= rowEnd; i ++) 
                matrix[i][colEnd] = num ++;
            // updating  end colund as current endColumn fully filled
            colEnd --;
            
            // going left to right
            
            for (int i = colEnd; i >= colStart; i --) 
                if (rowStart <= rowEnd)
                    matrix[rowEnd][i] = num ++;
            // updating end row as current end Row fully filled
            rowEnd --;
            
            //goind bottom to top
            
            for (int i = rowEnd; i >= rowStart; i --) 
                if (colStart <= colEnd)
                    matrix[i][colStart] = num ++;
            // updating starting colum as current startcolum fully filled
            colStart ++;
        }
        
        return matrix;
    }
};