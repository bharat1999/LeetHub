class Solution {
    map<int,list<int>> adj;
    vector<bool> visited,recStack;
    bool DFS(int i)
    {
        if(!visited[i])
        {
            visited[i]=true;
            recStack[i]=true;
            for(auto x:adj[i])
            {
                // if neighbour not visited and its DFS give true means cycle
                if(!visited[x] and DFS(x))
                    return true;
                // is neighbour visited and its already in recursion stack means its a back edge
                // so return true for cycle detected
                if(recStack[x])
                    return true;
            }
        }
        // remove current node from recursion stack and return false
        recStack[i] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        visited.resize(numCourses,false);
        recStack.resize(numCourses,false);
        for(auto x:p)
            adj[x[1]].push_back(x[0]);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] and DFS(i))
                return false;
        }
        return true;
    }
};