class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        for(auto x:matrix)
            for(auto y:x)
                arr.push_back(y);
        sort(arr.begin(),arr.end());
        int n = arr.size();
        return arr[k-1];
    }
};