class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return {};
        int start=nums[0];
        vector<string> ans;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]==nums[i]+1)
            {
                continue;
            }
            else
            {
                if(start==nums[i])
                    ans.push_back(to_string(nums[i]));
                else
                    ans.push_back(to_string(start)+"->"+to_string(nums[i]));
                start = nums[i+1];
            }
        }
        if(start==nums[n-1])
            ans.push_back(to_string(nums[n-1]));
        else
            ans.push_back(to_string(start)+"->"+to_string(nums[n-1]));
        return ans;
    }
};