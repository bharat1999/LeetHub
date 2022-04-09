class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        for(auto x:mp)
        {
            heap.push({x.second,x.first});
            if(heap.size()>k)
                heap.pop();
        }
        vector<int> ans;
        while(!heap.empty())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};