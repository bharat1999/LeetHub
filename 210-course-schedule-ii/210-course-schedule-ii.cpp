class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> inDegree(n,0);
        map<int,list<int>> adj;
        for(auto x:p)
        {
            adj[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
        vector<int> topoOrder;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            // decrease in degree of all neighbours by q
            for(auto x:adj[cur])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
            // add current to topoOrder
            topoOrder.push_back(cur);
        }
        // if topoOrder size equal to n meanas no cycle
        if(topoOrder.size()==n)
            return topoOrder;
        // else means we have a cycle
        return {};
    }
};