class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        unordered_map<int,string> row;
        unordered_map<string,int> freq;
        for(int i=0;i<r;i++)
        {
            string temp = "";
            for(int j=0;j<c;j++)
                temp+=to_string(grid[i][j])+" ";
            row[i]=temp;
        }
        for(int i=0;i<c;i++)
        {
            string temp = "";
            for(int j=0;j<r;j++)
                temp+=to_string(grid[j][i])+" ";
            freq[temp]++;
        }
        int ans = 0;
        for(int i=0;i<r;i++)
            ans+=freq[row[i]];
        return ans;
    }
};