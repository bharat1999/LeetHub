class Solution {
public:
    class tuple
    {
        public:
        int node; // on which current node we are standing
        int mask; // mask of that node
        int cost; // cost of path explore by this node
        tuple(int node, int mask, int cost)
        {
            this -> node = node;
            this -> mask = mask;
            this -> cost = cost;
        }
    };
    
    
    int shortestPathLength(vector<vector<int>>& graph) {
        // total number of nodes present
        int n = graph.size(); 
        
        
        queue<tuple> q; 
        
         // set to take care which path we have already visited
        set<pair<int, int>> visited;
        
        int all = (1 << n) - 1; // if all nodes visited then its mask will be equal to this
            
        // we don't know which node will give us shortest path so intially for all nodes we will store in our queue
        for(int i = 0; i < n; i++)
        {
            // its the current path 
            int maskValue = (1 << i); // 2 ^ i
            
            tuple thisNode(i, maskValue, 0); // make a tuple for every node
            
            q.push(thisNode);
            
            visited.insert({i, maskValue}); // also update into our set
        }
        
        // Implementing BFS
        while(q.empty() == false) // until queue is not empty
        {
            tuple curr = q.front(); // extracting front tuple
            q.pop(); // pop from queuu
            
            // if mask value becomes all, that means we have visited all of our nodes, so from here return cost
            if(curr.mask == all) 
                return curr.cost;
            
            // if not, start exploring in its adjcant
            for(auto &adj: graph[curr.node])
            {
                // its the path visited till current node
                int bothVisitedMask = curr.mask; // current mask
                
                // we are moving from one node to anothor node
                // getting new mask
                bothVisitedMask = bothVisitedMask | (1 << adj); 
                
                tuple ThisNode(adj, bothVisitedMask, curr.cost + 1);
                
                // if paths from current node is not visited than add to set and queue
                if(visited.find({adj, bothVisitedMask}) == visited.end())
                {
                    visited.insert({adj, bothVisitedMask});
                    q.push(ThisNode); 
                }
            }
            
        }
        
        // return -1, but this condition will never come
        return -1;
    }
};