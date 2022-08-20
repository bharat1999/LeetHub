class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& s) {
        // to store which station we encountered till now have max petrol
        priority_queue<int> heap;
        // so that we calculate to reach target also
        s.push_back({target,0});
        int ans  = 0;
        for(int i=0;i<s.size();i++)
        {
            // reduce the distance till current station
            // if first station reduce fuel till their
            if(i==0)
                fuel-=s[i][0];
            // otherwisw fueld used will be dis [cur] - dis [cur-1]
            else
                fuel-=s[i][0]-s[i-1][0];
            // if fuel is less than needed take from prev visited stations
            while(fuel<0 and !heap.empty())
            {
                fuel+=heap.top();
                heap.pop();
                ans++;
            }
            // if fuel is still less return -1
            if(fuel<0)
                return -1;
            // add petrol of visited station
            heap.push(s[i][1]);
        }
        return ans;
    }
};