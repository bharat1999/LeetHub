class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m!=r*c)
            return mat;
        int i=0,j=0;
        vector<vector<int>> res(r,vector<int> (c));
        {
            for(auto x:mat)
            {
                for(auto y:x)
                {
                    if(j==c)
                    {
                        j=0;
                        i++;
                    }
                    res[i][j++]=y;
                }
            }
        }
        return res;
        
    }
};