class Solution {
    vector<vector<int>> paths;
     void DFS(vector<vector<int>>&graph ,int target,int cur,vector<int> temp)
     {
        temp.push_back(cur);
        if(cur==target)
        {    
            paths.push_back(temp);
            return;
        }
        // visit neighbour of cur node
        for(auto x:graph[cur])
            DFS(graph,target,x,temp);
     }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> tmp;
        DFS(graph,n-1,0,tmp);
        return paths;
    }
};