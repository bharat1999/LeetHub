class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return {};
        vector<string> ans;
        int left = nums[0];
        int right = nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
                right = nums[i];
            else
            {
                if(left == right)
                    ans.push_back(to_string(left));
                else
                    ans.push_back(to_string(left) + "->" + to_string(right));
                left = right = nums[i];
            }
        }
        if(left == right)
            ans.push_back(to_string(left));
        else
            ans.push_back(to_string(left) + "->" + to_string(right));
        return ans;
    }
};