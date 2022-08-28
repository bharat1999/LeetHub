class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>> cols,rows;
        int n = mat.size();
        int m = mat[0].size();
        for(int j=0;j<m;j++)
        {
            int r = 0;
            int c = j;
            while(r<n and c<m)
                cols[j].push_back(mat[r++][c++]);
                
        }
        for(int i=1;i<n;i++)
        {
            int r = i;
            int c = 0;
            while(r<n and c<m)
                rows[i].push_back(mat[r++][c++]);
                
        }
        for(auto &x:cols)
            sort(x.second.begin(),x.second.end());
        for(auto &x:rows)
            sort(x.second.begin(),x.second.end());      
        
        for(int j=0;j<m;j++)
        {
            int r = 0;
            int c = j;
            vector<int> tmp = cols[j];
            int i = 0;
            while(r<n and c<m)
                mat[r++][c++] = tmp[i++];
                
        }
        for(int i=1;i<n;i++)
        {
            int r = i;
            int c = 0;
            vector<int> tmp = rows[i];
            int j = 0;
            while(r<n and c<m)
                mat[r++][c++] = tmp[j++];
        }          
        return mat;
    }
};