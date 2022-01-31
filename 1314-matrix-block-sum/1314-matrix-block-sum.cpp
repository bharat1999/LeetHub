class Solution {
public: 
    int m,n;
    // to check valid index and return its value
    int extractSum(int i, int j, const vector<vector<int>>& sum) 
    {
        if (i < 0 || j < 0) return 0;
        if (i >= m) i = m - 1;
        if (j >= n) j = n - 1;
        return sum[i][j];
    }
        
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        m = mat.size();
        n = mat[0].size();
        
        vector<vector<int>> sum(m, vector<int>(n, 0));
        // Calculate prefix matrix = where prefix[i][j] is sum of all elements till i,j that is a rectangle
        // starting at 00 and ending at i,j
        for (int i = 0; i < m; i++) 
        {
            // we are adding top and left of current and than delete top left once because it is present in             //both top and left than we add the element at current index
            for (int j = 0; j < n; j++)
                sum[i][j]=mat[i][j]+extractSum(i-1,j,sum) + extractSum(i,j-1,sum)-extractSum(i-1,j-1, sum);
        }
        
        // Use prefix matrix to calculate our sum
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) 
        {
            // ans[i][j] is the sum of all elements which is centered at i,j with side = 2k + 1
            for (int j = 0; j < n; j++)
                ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);
        }
        
        return ans;
    }
};