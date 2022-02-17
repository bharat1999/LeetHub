class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        // to keep count of LIS sequences till i
        vector<int> count(n,1);
        int ans=1;
        // filling our dp array with LIS for each subsequence till i
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    // means we get a new LIS , so copy the count
                    if(lis[j]+1>lis[i])
                    {
                        // update LIS
                        lis[i]=lis[j]+1;
                        //Update number of LIS till i
                        count[i]=count[j];
                    }
                    //means we already have a same LIS so we increment the 
                    //count
                    else if(lis[j]+1==lis[i])
                        count[i]+=count[j];
                }
            }
            ans=max(ans,lis[i]);
        }
        // checking how many LIS 
        int noOfLIS=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]==ans)
                noOfLIS+=count[i];
        }
        return noOfLIS;
    }
};