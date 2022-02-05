class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        for(int right = 0;right<n;right++)
        {
            // add current element to sum
            sum+=nums[right];
            //while sum is >= target we will reduce size till its greater to get
            // minimum subarray size
            while(sum>=target)
            {
                ans = min(ans,right-left+1);
                sum-=nums[left++];
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};