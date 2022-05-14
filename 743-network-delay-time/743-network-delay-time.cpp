class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto x:times)
        {
            mp[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        vector<int> receiveTime(n+1,INT_MAX);
        receiveTime[k] = 0;
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int curTime = cur.second;
            for(auto x:mp[cur.first])
            {
                int neighbourLabel = x.first;
                int neighbourTime = x.second;
                int arrivalTime = neighbourTime + curTime;
                if(receiveTime[neighbourLabel]>arrivalTime)
                {
                    receiveTime[neighbourLabel] = arrivalTime;
                    q.push({neighbourLabel,arrivalTime});
                }
            }   
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
            ans = max(ans,receiveTime[i]);
        return ans==INT_MAX?-1:ans;
    }
};