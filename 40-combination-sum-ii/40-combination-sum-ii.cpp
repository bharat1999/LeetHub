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
            // num should be <= target and the number should be the first of                //array or should not be equal to prev elements
            if(c[i]<=target and (i==s or c[i]!=c[i-1]))
            {
                tmp.push_back(c[i]);
                solve(c,i+1,target-c[i],tmp);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        solve(candidates,0,target,tmp);
        return ans;
    }
};