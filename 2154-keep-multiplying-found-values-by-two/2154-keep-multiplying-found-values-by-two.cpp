class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s(nums.begin(),nums.end());
        for(auto a:s)
            if(a==original) original*=2;
        return original;
    }
};