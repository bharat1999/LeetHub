class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                c++;
            }
        }
        if(c>1)
            return false;
        for(int i=0;i<n-1;i++)
        {
            // check is replacement possible
            if(nums[i]>nums[i+1])
            {
                if(i==0)
                    nums[i]=nums[i+1];
                else if(i==n-2)
                    nums[i+1]=nums[i];
                else
                {
                    if(nums[i-1]<=nums[i+1])
                        nums[i]=nums[i+1];
                    else if(nums[i]<nums[i+2])
                        nums[i+1]=nums[i];
                    else 
                        return false;
                }
            }
        }
        return true;
    }
};