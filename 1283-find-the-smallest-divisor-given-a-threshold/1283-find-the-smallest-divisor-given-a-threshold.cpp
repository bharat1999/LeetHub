class Solution {
    bool check(vector<int>& nums,int m,int t)
    {
        int div = 0;
        for(auto x:nums)
        {
            div+=x/m;
            if(x%m) div++;
        }
        return div<=t;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e)
        {
            int m = e-(e-s)/2;
            if(check(nums,m,threshold))
            {
                ans = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        return ans;
    }
};