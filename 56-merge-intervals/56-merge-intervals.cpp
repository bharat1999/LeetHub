class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    { 
        sort(intervals.begin(),intervals.end()); // sorting by first value
        vector<vector<int>> res;
        for(auto x:intervals)
        {
            if(res.empty() or res.back()[1]<x[0]) // if res is empty or
            //end of last in res is less than start of x means no overlap than push
                res.push_back(x);
            else // otherwise update end of merged by taking max of new and current end
                res.back()[1]= max(res.back()[1],x[1]);
        }        
        return res;
    }
};