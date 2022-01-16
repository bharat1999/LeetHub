class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums)
        {
            if(mp.find(x)!=mp.end())
                return true;
            else
                mp[x]++;
        }
        return false;
    }
};