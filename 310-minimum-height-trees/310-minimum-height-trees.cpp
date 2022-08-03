class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // TOPOSORT
        if(n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(q.size()){
            int len = q.size();
            ans = {};
            while(len--){
                int curr = q.front();
                q.pop();
                indegree[curr]--;
                for(auto next : adj[curr]){
                    indegree[next]--;
                    if(indegree[next] == 1) q.push(next);
                }
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};