class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> visited;
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1]+nums[i];
        int s=0,e=0;
        int ans=INT_MIN;
        while(e<n)
        {
            if(visited.count(nums[e]))
            {
                if(s!=0)
                    ans=max(ans,prefix[e-1]-prefix[s-1]);
                else
                    ans=max(ans,prefix[e-1]);
                while(visited.count(nums[e]))
                {
                    visited.erase(visited.find(nums[s]));
                    s++;
                }                    
            }
            visited.insert(nums[e]);
            e++;
        }
        if(s!=0)
            ans=max(ans,prefix[e-1]-prefix[s-1]);
        else
            ans=max(ans,prefix[e-1]);
        return ans;
    }
};