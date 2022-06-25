class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(idx!=-1)
                    return false;
                idx=i;
            }
        }
        if(idx==-1 or idx==0 or idx==n-2 or nums[idx-1]<=nums[idx+1] or nums[idx]<=nums[idx+2])
            return true;
        return false;
    }
};