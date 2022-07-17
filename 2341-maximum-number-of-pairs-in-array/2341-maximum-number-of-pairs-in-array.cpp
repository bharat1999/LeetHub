class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        int p=0;
        for(auto x:mp)
            p+=x.second/2;
        return {p,(int)nums.size()-(2*p)};
        
    }
};