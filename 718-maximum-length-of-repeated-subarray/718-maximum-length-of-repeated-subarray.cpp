class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
    int ans=0;
    int n = nums1.size();
    int m = nums2.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            // if both equal anwer will be 1 plus max equal till i+1 j+1
            if(nums1[i]==nums2[j]) 
            {
                dp[i][j] = dp[i+1][j+1]+1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    return ans;
    }
};