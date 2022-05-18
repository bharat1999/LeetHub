class Solution {
private:
    // low is earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree
    //rooted with current vertex
    // disc is the first discovery time of each node
    vector<int> low, disc;
    int timer = 0;
    vector<vector<int>> res;

private:
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;
        disc[node] = low[node] = timer++;
        
        for(auto &it : adj[node])
        {
            if(it == parent) continue;
            
            if(!vis[it])
            {
                dfs(it, node, adj, vis);
                
                // update low bcz if their is back edge from neighbour
                low[node] = min(low[node], low[it]);
                // if earliest visited node time is greater than disc of root it means its bridge
                if(low[it] > disc[node])
                {
                    res.push_back({node, it});
                }
             }
            
            else{
                low[node] = min(low[node], disc[it]);
             }
        }
    }
    
public:    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        
        
        vector<int> adj[n];
        for(auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        low.resize(n);
        disc.resize(n);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
                dfs(i, -1, adj, vis);                
        }
        
        
        return res;
    }
};