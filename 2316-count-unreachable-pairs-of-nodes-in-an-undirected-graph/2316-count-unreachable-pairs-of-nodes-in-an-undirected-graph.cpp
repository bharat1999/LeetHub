class Solution {
    unordered_map<int,list<int>> adj;
    void DFS(int v,vector<bool> &visited,long long &count,long long &tmp)
    {
        visited[v] = true;
        count++;
        tmp++;
        // Recur for all the vertices
        // adjacent to this vertex
        for (auto x:adj[v])
            if (!visited[x])
                DFS(x, visited,count,tmp);
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        long long count = 0;
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            long long tmp =0;
            if(!visited[i])
            {
                cout<<i<<" ";
                DFS(i,visited,count,tmp);
                ans+=tmp*(n-count);
            }
        }
        return ans;
    }
};