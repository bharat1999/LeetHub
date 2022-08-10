class Solution {
    
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int n = nums.size();
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
                // but as r = 2 if we observe it will be number of n natural number so we can 
                // directly use formula
                long long tuples = ((x.second-1)*x.second)/2;
                ans+=tuples;
            }
        }
        // now each valid tuple make 8 possible orientaions so add to answer
        return ans*8;
    }
};