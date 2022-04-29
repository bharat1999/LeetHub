class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);    
        for(int i=0;i<n;i++)          
        {
            if(color[i]) 
                continue;          // if already coloured then continue
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty())
            {
                int parent=q.front();
                q.pop();
                for(int child:graph[parent])
                {
                    // if not colored color it
                    if(color[child]==0)
                    {
                        color[child]=-color[parent];
                        q.push(child);
                    }
                    // if colored
                    else
                    {
                        if(color[parent]==color[child]) 
                            return false;    
                        // if parent and child have same colour then return false;
                    }
                }
            }

        }
        return true;
    }
};