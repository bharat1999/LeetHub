class Solution {
    vector<vector<int>> sol;
    void solve(int i,int &k,int &n,vector<int> tmp,int sum)
    {
        if(sum == n and tmp.size()==k)
        {
            sol.push_back(tmp);
            return;
        }
        if(sum>n or tmp.size()>k)
            return;
        if(i>9)
            return;
        tmp.push_back(i);
        solve(i+1,k,n,tmp,sum+i);
        tmp.pop_back();
        solve(i+1,k,n,tmp,sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1,k,n,{},0);
        return sol;
    }
};