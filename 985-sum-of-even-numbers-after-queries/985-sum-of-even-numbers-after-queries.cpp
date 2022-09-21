class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        vector<int> ans;
        for(auto x:nums)
        {
            if(x%2==0)
                evenSum+=x;
        }
        for(auto x:queries)
        {
            int v = x[0];
            int idx = x[1];
            // nums[idx] = odd
            if(nums[idx]%2)
            {
                // odd + odd = even
                if(v%2)
                    evenSum+=nums[idx]+v;
            }
            // nums[idx] = even
            else 
            {
                // both even so sum increase by v
                if(v%2==0)
                    evenSum+=v;
                // v odd so nums[idx] become odd so subtact
                else
                    evenSum-=nums[idx];
            }
            nums[idx]+=v;
            ans.push_back(evenSum);
        }
        return ans;
    }
};