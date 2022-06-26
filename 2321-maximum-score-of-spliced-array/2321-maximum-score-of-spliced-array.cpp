class Solution {
    int s(vector<int> &a,vector<int> &b)
    {
        int sum = accumulate(a.begin(),a.end(),0);
        int curSum=0;
        int maxSum=0;
        for(int i=0,n=a.size();i<n;i++)
        {
            curSum+=b[i]-a[i];
            if(curSum<0)
                curSum=0;
            maxSum=max(maxSum,curSum);
        }
        return sum + maxSum;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(s(nums1,nums2),s(nums2,nums1));

    }
};