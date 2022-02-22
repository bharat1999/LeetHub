class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefix;
        // their will always we an array having 0 sum that is empty
        prefix[0]++;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            // we have to add the number of times that sum exist already
            count+=prefix[sum-k];
            prefix[sum]++;
        }
        return count;
    }
};