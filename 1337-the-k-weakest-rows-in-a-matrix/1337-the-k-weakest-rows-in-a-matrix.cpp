class Solution {
   static bool comparator(pair<int,int>&a ,pair<int,int>& b)
    {
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> ans;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            int t=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    t++;
                else
                    break;
            }
            ans.push_back({t,i});
        }
        sort(ans.begin(),ans.end(),comparator);
        int i=0;
        vector<int> sol;
        while(k--)
        {
            sol.push_back(ans[i].second);
            i++;
        }    
        return sol;
    }
};