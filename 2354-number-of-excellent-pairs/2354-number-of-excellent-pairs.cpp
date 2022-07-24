class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> used;
        vector<int> bits;
        for(auto x:nums)
        {
            // we will take a no only once as we need distinct pair
            if(used.count(x)!=0)
                continue;
            bits.push_back(__builtin_popcount(x));
            used.insert(x);
        }
        sort(bits.begin(),bits.end());
        long long ans = 0;
        int n = bits.size();
        for(auto x:bits)
        {
            int req = k - x;
            auto it = lower_bound(bits.begin(),bits.end(),req) - bits.begin();
            // as it is the smallest index >= req so all after that will be in answer
            ans+=n - it;
        }
        return ans;
    }
};