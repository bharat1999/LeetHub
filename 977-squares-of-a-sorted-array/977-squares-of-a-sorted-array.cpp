class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int i=e; // we will fill from end
        vector<int> ans(nums.size());
        while(s<=e)
        {
            if(abs(nums[s])<abs(nums[e]))
            {
                ans[i--]=nums[e]*nums[e];
                e--;
            }
            else
            {
                ans[i--]=nums[s]*nums[s];
                s++;
            }
        }
        return ans;
    }
};