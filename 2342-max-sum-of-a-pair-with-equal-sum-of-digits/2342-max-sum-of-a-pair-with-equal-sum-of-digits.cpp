class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> digitSum;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        for(auto x:nums)
        {
            int sum = 0;
            int y = x;
            while(y)
            {
                sum+=y%10;
                y/=10;
            }
            mp[sum].push(x);
            if(mp[sum].size()>2)
                mp[sum].pop();
        }
        int ans = -1;
        for(auto x:mp)
        {
            if(x.second.size()!=2)
                continue;
            int a = x.second.top();
            x.second.pop();
            int b = x.second.top();
            ans=max(ans,a+b);
        }
        return ans;
    }    
};