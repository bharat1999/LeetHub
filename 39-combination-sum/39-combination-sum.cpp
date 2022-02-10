class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& c,int s,int target,vector<int> tmp)
    {
        if(target==0)
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=s,n=c.size();i<n;i++)
        {
            if(c[i]<=target)
            {
                tmp.push_back(c[i]);
                solve(c,i,target-c[i],tmp);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        solve(candidates,0,target,tmp);
        return ans;
    }
};