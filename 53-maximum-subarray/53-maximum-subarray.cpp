class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,curmax=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]>=0)
                sum+=nums[i];
            else
                sum=0;
            curmax=max(curmax,sum);
        }
        if(curmax==0) // mean all are negative
        {
            curmax=INT_MIN;
            for(auto x:nums)
                curmax=max(curmax,x);
        }
        return curmax;
    }
};