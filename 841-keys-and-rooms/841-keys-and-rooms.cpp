class Solution {
    void dfs(vector<vector<int>>& rooms,int node,unordered_set<int>& visited)
    {
        if(visited.count(node))
            return;
        visited.insert(node);
        for(auto x:rooms[node])
            dfs(rooms,x,visited);
    }
    void bfs(vector<vector<int>>& rooms,int node,unordered_set<int>& visited)
    {
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto x:rooms[cur])
                if(visited.find(x)==visited.end())
                {
                    visited.insert(x);
                    q.push(x);
                }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //no key in 0 room
        if(rooms[0].size()==0)
            return false;
        unordered_set<int> visited;
        bfs(rooms,0,visited);
        return visited.size()==rooms.size();
    }
};