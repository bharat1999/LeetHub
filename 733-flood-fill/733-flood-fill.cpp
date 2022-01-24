class Solution {
    void solve(vector<vector<int>>& image,int sr,int sc,int color,int m,int n,vector<vector<bool>>& visited)
    {
        //base case handled in call to avoid extra calls
        visited[sr][sc]=true;
        // color up
        if(sr-1>=0 and image[sr-1][sc]==image[sr][sc] and visited[sr-1][sc]==false) 
            solve(image,sr-1,sc,color,m,n,visited);
        // color right
        if(sc+1<n and image[sr][sc+1]==image[sr][sc] and visited[sr][sc+1]==false) 
            solve(image,sr,sc+1,color,m,n,visited);
        // color down
        if(sr+1<m and image[sr+1][sc]==image[sr][sc] and visited[sr+1][sc]==false) 
            solve(image,sr+1,sc,color,m,n,visited);
        // color left
        if(sc-1>=0 and image[sr][sc-1]==image[sr][sc] and visited[sr][sc-1]==false) 
            solve(image,sr,sc-1,color,m,n,visited);
        image[sr][sc] = color;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n));
        solve(image,sr,sc,newColor,m,n,visited);
        return image;
    }
};