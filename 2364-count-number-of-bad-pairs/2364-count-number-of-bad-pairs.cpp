class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        long long n = nums.size();
        long long bad = ((n-1)*(n))/2;
        for(int i=0;i<n;i++)
        {
            int sum1 = i- nums[i];
            bad-=mp[sum1];
            mp[i-nums[i]]++;

        }
        return bad;
    }
};