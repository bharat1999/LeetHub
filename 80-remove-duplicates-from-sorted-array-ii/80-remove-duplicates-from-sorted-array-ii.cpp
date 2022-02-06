class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) 
            return n;
        int count=1,idx=1;
        for(int i=1;i<n;i++)
        {
            // same number so increase count
            if(nums[i-1]==nums[i]) 
                count++;
            // new number so make count 1
            else count=1;
            //count is less than equal to 2 than its valid to put ith value at idx
            if(count<=2) nums[idx++]=nums[i];
        }
        return idx;
    }
};