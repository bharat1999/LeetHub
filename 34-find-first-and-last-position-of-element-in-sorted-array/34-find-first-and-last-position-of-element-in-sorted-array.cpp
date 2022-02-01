class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int first=-1;
        int second=-1;
        while(s<=e)
        {
            int m=(s+e)/2;
            if(nums[m]==target) // mil gaya to piche find karo
            {
                first=m;
                e=m-1;
            }
            else if(nums[m]<target)
                s=m+1;
            else
                e=m-1;
        }
        s=0;
        e=nums.size()-1;
        while(s<=e)
        {
            int m=(s+e)/2;
            if(nums[m]==target) // mil gaya to piche find karo
            {
                second=m;
                s=m+1;
            }
            else if(nums[m]<target)
                s=m+1;
            else
                e=m-1;
        }
        return {first,second};
    }
};