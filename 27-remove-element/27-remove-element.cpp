class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int toplace = 0;
        for(auto x:nums)
        {
            if(x!=val)
                nums[toplace++]=x;
        }
        return toplace;
    }
};