class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int t = target-nums[i]-nums[j];
                int s = j+1;
                int e = n-1;
                while(s<e)
                {
                    if(nums[s]+nums[e]==t)
                    {
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;
                        while(s<e and nums[s-1]==nums[s])
                            s++;
                    }
                    else if(nums[s]+nums[e]<t)
                        s++;
                    else
                        e--;
                }
                while(j+1<n and nums[j]==nums[j+1])
                    j++;
            }
            while(i+1<n and nums[i]==nums[i+1])
                    i++;
        }
        return ans;
    }
};