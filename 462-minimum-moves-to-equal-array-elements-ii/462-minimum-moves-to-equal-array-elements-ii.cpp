class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t = nums[nums.size()/2];
        int count = 0;
        for(int x:nums)
            count+=abs(x-t);
        return count;
    }
};