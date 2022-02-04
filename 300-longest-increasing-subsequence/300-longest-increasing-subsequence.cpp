class Solution {
    int binarySearch(int s, int e, vector<int>& dp, int target) // using to get index of element next greater then target
    {
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(dp[mid] == target)
            {
                return mid;
            }
            else if(dp[mid] < target)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }  
        return s;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] > dp.back())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                // we can also use upperbound
                int idx = binarySearch(0, dp.size()-1, dp, nums[i]);
                dp[idx] = nums[i];
            }
        }
        
        return dp.size();
    }
};