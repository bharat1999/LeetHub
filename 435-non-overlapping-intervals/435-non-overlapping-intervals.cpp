class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        //ans was initially made -1 because our prev and intervals[0] will always match
        int ans=-1;      
		if(v.size()==0) 
            return 0;       
        // sorted by end bcz smallest end will have max possible overlap
		sort(v.begin(),v.end(),comp);
		int prev = v[0][1];
		for(auto x: v) 
        {
    //we dont update previous, because i[1] will be greater then prev[1]
			if(prev>x[0]) 
				ans++;    
            // we want the end point to be minimum
		    else 
                prev=x[1];           
		}
		return ans;                 
    }
};