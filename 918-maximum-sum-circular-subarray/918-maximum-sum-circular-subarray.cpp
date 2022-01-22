class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int cur_max = 0;
        int cur_min = 0;
        int total_sum = 0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            total_sum+=nums[i];
            cur_max = max(cur_max + nums[i],nums[i]);
            max_sum = max(cur_max,max_sum);
            cur_min = min(cur_min + nums[i],nums[i]);
            min_sum = min(cur_min,min_sum);
        }
        if(max_sum<0)
            return max_sum;
        return max(max_sum,total_sum - min_sum);
    }
};