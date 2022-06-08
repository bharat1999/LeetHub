class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int req = nums.size()/3;
        for(auto x:nums)
            mp[x]++;
        vector<int> sol;
        for(auto x:mp)
        {
            if(x.second>req)
                sol.push_back(x.first);
        }
        return sol;
    }
};