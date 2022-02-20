class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sorting by start of interval
        sort(intervals.begin(),intervals.end());
        int start = -1;
        int end = -1;
        int ans = 0;
        for (auto& x: intervals) 
        {
            // If start and ending of curent is greater
            // than start and end it means a new interval
            // so update start
            if (x[0] > start && x[1] > end) 
            {
                start = x[0];
                ans++;
            }
            end = max(end, x[1]);
        }
        return ans;
    }
};