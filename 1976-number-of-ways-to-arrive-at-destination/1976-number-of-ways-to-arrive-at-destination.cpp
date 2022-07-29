class Solution {
    #define ll long long
    #define mod 1000000007
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using pi = pair<ll,ll>;
        ll min_dis = LONG_MAX;
        vector<vector<ll>> adj[n];
        for(vector<int> a:roads)
        {
            ll u = a[0];
            ll v = a[1];
            ll wt = a[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<ll> dist(n,LONG_MAX);
        vector<ll> ways(n);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pi,vector<pi>,greater<pi>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            ll cur_dis = p.first;
            ll cur_node = p.second;
        
            for(auto arr : adj[cur_node])
            {
                ll new_dis = cur_dis + arr[1];
                ll new_node = arr[0];
                
                if(new_dis < dist[new_node])
                {
                    dist[new_node] = new_dis;
                    q.push({new_dis,new_node});
                    ways[new_node] = ways[cur_node];
                }
                else if(new_dis == dist[new_node])
                    ways[new_node] = (ways[cur_node]%mod + ways[new_node])%mod;
            }
        }    
        return ways[n-1];
    }
};