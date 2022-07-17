class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        int l = nums[0].size();
        for(auto x:queries)
        {
            priority_queue<pair<string,int>> pq;
            int k = x[0];
            int t = x[1];
            int i;
            for(i=0;i<n;i++)
            {
                int idx = l-t;
                string tmp = nums[i].substr(idx);
                pq.push({tmp,i});
                if(pq.size()>k)
                    pq.pop();
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};