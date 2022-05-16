class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;    
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
// we need to find no. of numbers which are in range ( v[j]-v[i])+1 , v[j]+v[i]-1 ) inclusive from index j+1 to n-1 inclusive 
            ans+=upper_bound(nums.begin()+(j+1),nums.end(),nums[i]+nums[j]-1)-(nums.begin()+(j+1));
            
            }
        }
        return ans;
    }
};