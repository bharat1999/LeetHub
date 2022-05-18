class Solution {
    unordered_map<int,vector<int>> adj;
    void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridges)
    {
        static int time = 0;    //static timestamp to take memory once
        disc[u] = low[u] = time;
        time +=1;
        
        for(int v: adj[u])
        {
            if(disc[v]==-1) //If v is not visited
            {
                parent[v] = u;
                DFS(v,disc,low,parent,bridges);
                // after visiting neighbour of u , we update low of u 
                // bcz their can be a backedge from v so that reach time of u cna be lower
                low[u] = min(low[u],low[v]);
                
                // if low of v is greater than discovery time of u 
                // that means their is no back edge so add to bridge
                if(low[v] > disc[u])
                    bridges.push_back(vector<int>({u,v}));
            }
            // if v is not parent of u check for back edge from u to v
            else if(v!=parent[u])
                low[u] = min(low[u],disc[v]);
        }
    }
    void findBridges_Tarjan(int V,vector<vector<int>>& bridges)
    {
        // disc will have first discovery time of each node 
        // low will have the earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with current node
        vector<int> disc(V,-1),low(V,-1),parent(V,-1);
        //Apply DFS for each component
        for(int i=0;i<V;++i)
            if(disc[i]==-1)
                DFS(i,disc,low,parent,bridges);
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Adjancy List
        for(int i=0;i<connections.size();++i)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<vector<int>> bridges; //Store all the bridges as pairs
        findBridges_Tarjan(n,bridges); // Applying Tajan's Algo
        return bridges;
    }
};