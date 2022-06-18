class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        vector<int> prefix(n,0),suffix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            suffix[i] = suffix[i+1] + nums[i];
        
        // finding pivot;
        for(int i=0;i<n;i++)
        {
            // we at leftmost elements
            if(i==0)
            {
                if(suffix[i+1]==0)
                    return 0;
            }
            // if at rightmost
            else if(i==n-1)
            {
                if(prefix[i-1]==0)
                    return n-1;
            }
            // check normal case
            else if(prefix[i-1]==suffix[i+1])
                return i;
        }
        return -1;
    }
};