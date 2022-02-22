class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n),suffix(n),res(n);
        // for first element prefix have no elements
        prefix[0]=1;
        // for last element suffix have no elements considering 0 as last
        suffix[0]=1;
        for(int i=1;i<n;i++)
        {
            // as prefix[i-1] have product except i-1th element
            prefix[i]=prefix[i-1]*nums[i-1];
            // prefix[i-1] have product of all from n-i+1 till n-1
            // so include 
            suffix[i]=suffix[i-1]*nums[n-i];
        }
        for(int i=0;i<n;i++)
            res[i]=prefix[i]*suffix[n-i-1];
        return res;
    }
};