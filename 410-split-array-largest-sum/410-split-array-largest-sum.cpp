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
        cout<<sum<<" "<<count<<endl;
        return count<=m;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto x:nums)
            sum+=x;
        int s = 0;
        int e = sum;
        int ans=INT_MAX;
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