class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int s = 0;
        int n = nums.size();
        int e = 0;
        long long sum=0;
        while(e<n)
        {
            sum+=nums[e];
            // range more than requried so calculate answer till now
            if(sum*(e-s+1)>=k)
            {
                // increase s to be in range
                while(sum*(e-s+1)>=k)
                    sum-=nums[s++];
            }
            ans+=e-s+1;
            e++;
        }
        return ans;
    }
};