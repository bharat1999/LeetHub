class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> nums,int s)
    {
        if(s==nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=s,n=nums.size();i<n;i++)
        {
            if(i==s or nums[i]!=nums[s])
            {
                swap(nums[s],nums[i]);
                solve(nums,s+1);
            }    
        }
            
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};