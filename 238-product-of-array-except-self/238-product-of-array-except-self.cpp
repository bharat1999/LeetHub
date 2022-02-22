class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n),suffix(n),res(n);
        // for first element prefix is that element itself
        prefix[0]=nums[0];
        // for last element suffix product is that element itself
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            // as prefix[i-1] have product except ith element
            prefix[i]=prefix[i-1]*nums[i];
            // prefix[i-1] have product of all 
            // so include 
            suffix[n-i-1]=suffix[n-i]*nums[n-i-1];
        }
        res[0]=suffix[1];
        res[n-1]=prefix[n-2];
        for(int i=1;i<n-1;i++)
            res[i]=prefix[i-1]*suffix[i+1];
        return res;
    }
};