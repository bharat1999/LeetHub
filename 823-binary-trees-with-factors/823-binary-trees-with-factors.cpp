class Solution {
    int mod = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        // to avoid unnecessary checks
        sort(arr.begin(),arr.end());
        long long ans =0;
        unordered_map<int,long long> dp;
        for(auto x:arr)
            dp[x]=1;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 and dp[arr[i]/arr[j]]>0)
                    dp[arr[i]]+=(dp[arr[j]] * dp[arr[i]/arr[j]]);
            }
            ans+=dp[arr[i]];
        }
        return ans%mod;
    }
};