class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int diff= target- nums[i];
            if(m.count(diff)>0)
            {
                return {i,m[diff]};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};