class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return n;
        int i=2;
        for(int j=i;j<n;j++)
        {
            // we got the number to replace
            if(nums[j]!=nums[i-2])
                nums[i++]=nums[j];
        }
        return i;
    }
};