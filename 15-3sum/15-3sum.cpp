class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i==0 or nums[i]!=nums[i-1]) // avoid duplicate for first element
            {
                int t=0-nums[i];
                cout<<t<<endl;
                int s=i+1,e=n-1;
                while(s<e)
                {
                    if(nums[s]+nums[e]==t)
                    {
                        ans.push_back({nums[i],nums[s],nums[e]});
                        s++;
                        e--;
                        while(s<e and nums[s]==nums[s-1]) // to avoid not taking same number
                          s++;
                        while(s<e and nums[e]==nums[e+1]) // to avoid not taking same number
                          e--;
            
                    }    
                    else if(nums[s]+nums[e]<t)
                        s++;
                    else
                        e--;
                }
            }
        }
        return ans;
    }
};