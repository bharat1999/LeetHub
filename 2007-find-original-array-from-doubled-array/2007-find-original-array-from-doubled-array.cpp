class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2)
            return {};
        unordered_map<int,int> mp;
        sort(changed.begin(),changed.end());
        for(auto x:changed)
            mp[x]++;
        vector<int> ans;
        for(auto x:changed)
        {
            if(x!=0 and mp[2*x]>0 and mp[x]>0)
            {
                ans.push_back(x);
                mp[2*x]--;
                mp[x]--;
            }
            if(x==0 and mp[0]>1)
            {
                ans.push_back(x);
                mp[x]-=2;
            }
        }
        if(ans.size()==changed.size()/2)
            return ans;
        return {};
    }
};