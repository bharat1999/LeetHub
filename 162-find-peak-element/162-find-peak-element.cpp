class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        while(s<=e)
        {
            int mid = e - (e-s)/2;
            // if mid element is greater than both neighbours return mid 
    if((mid==0 or nums[mid]>nums[mid-1]) and (mid+1==n or nums[mid]>nums[mid+1]))
                return mid;
            // if right of mid is greater it can be possible answer so increase s
            else if(mid+1<n and nums[mid]<nums[mid+1])
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};