class Solution {
    bool isValid(int sum,vector<int>& nums,int m)
    {
        int count = 1;
        int n = nums.size();
        int i=0;
        int temp=0;
        while(i<n)
        {
            if(nums[i]>sum)
                return false;
            if(temp+nums[i]<=sum)
                temp+=nums[i];
            else
            {
                count++;
                temp=nums[i];
            }
            i++;
        }
        return count<=m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        int mx=-1;;
        for(auto x:nums)
            mx=max(mx,x);
        int s = mx;
        int e = sum;
        int ans;
        while(s<=e)
        {
            int mid = e - (e-s)/2;
            if(isValid(mid,nums,m))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};