class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> heap;
        for(auto y:arr)
        {
            heap.push({abs(x-y),y});
            if(heap.size()>k)
                heap.pop();
        }
        vector<int> ans;
        while(!heap.empty())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};