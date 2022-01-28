class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int s)
    {
        if(s==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=s;i<nums.size();i++)
        {
            swap(nums[i],nums[s]);
            solve(nums,s+1);
            swap(nums[i],nums[s]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;
    
    }
};