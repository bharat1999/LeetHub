class Solution {
public:
    int ans = -1;
    vector<int> vis;
    
    void dfs(int node, vector<int>& edges, vector<int>& visorder, int curr){
        if(node == -1)
            return;
        // if visited earlier
        if(vis[node] == 1)
        {
            if(visorder[node]>=1)
                ans = max(ans, curr - visorder[node]);
            return;
        }
        
        // mark as visited
        vis[node] = 1;
        // mark order of visit
        visorder[node] = curr;
        
        dfs(edges[node], edges, visorder, curr+1);
        
        visorder[node] = -1;
    }
    
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> visorder(n, -1);
        vis.resize(n, 0);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0)
                dfs(i, edges, visorder, 1);
        }
        
        return ans;
        
    }
};