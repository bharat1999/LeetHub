class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> max_heap; // {arr[i]-x, arr[i]}
        for(auto it: arr){
            max_heap.push({abs(it-x), it});
            if(max_heap.size() > k)
                max_heap.pop();
        }
        vector<int> ans;
        while(!max_heap.empty()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(ans.begin(), ans.end()); // O(klogk)
        return ans;
    }
    
};