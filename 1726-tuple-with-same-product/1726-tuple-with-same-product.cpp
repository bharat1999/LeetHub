class Solution {
    vector<int> dp;
    long long fact(int n)
    {
        if(n==0 or n==1)
            return 1;
        if(n<1e7 and dp[n]!=-1)
            return dp[n];
        return n * fact(n-1);
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int n = nums.size();
        dp.resize(1e7,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[nums[i]*nums[j]]++;
            }
        }
        long long ans = 0;
        for(auto x:mp)
        {
            if(x.second>=2)
            {
                // first we will caluclate how many tuples we can make  using ncr formula 
                // ex if we have 3 valid pairs for a product we can make 3c2 = 3 tuples
                int n = x.second;
                // cause we know fact of 2 = 2
                long long tuples = (fact(n)/2)/(fact(n-2));
                // now each valid tuple make 8 possible orientaions so add to answer
                ans+=(tuples*8);
            }
        }
        return ans;
    }
};