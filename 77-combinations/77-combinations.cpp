class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> &tmp,int n,int k,int i)
    {
        if(tmp.size()==k)
        {
            ans.push_back(tmp);
            return;
        }
        for(int j=i;j<=n;j++)
        {
            tmp.push_back(j);
            solve(tmp,n,k,j+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        solve(tmp,n,k,1);
        return ans;
        
    }
};