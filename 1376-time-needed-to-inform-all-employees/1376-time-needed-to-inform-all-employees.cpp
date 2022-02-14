class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> M;
        for(int i=0;i<n;i++)
            M[manager[i]].push_back(i);
            
        int ans=INT_MIN;
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty())
        {
            int s= q.size();
            while(n--)
            {
                int curManager = q.front().first;
                int curTime = q.front().second;
                int curDuration = curTime+informTime[curManager];
                q.pop();
                for(auto x:M[curManager])
                    q.push({x,curDuration});
                ans=max(ans,curDuration);
            }
        }
        return ans;
    }
};