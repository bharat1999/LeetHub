class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i==0 or nums[i]!=nums[i-1])
            {
                for(int e=n-1;e>i;e--)
                {
                    if(nums[e]-nums[i]==k)
                    {
                        ans++;
                        break;
                    }
                }
            } 
        }
        return ans;
    }
};