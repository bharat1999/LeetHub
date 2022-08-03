class Solution {
    vector<bool> visited;
    stack<int> st;
    map<int,list<int>> adj;
    vector<int> topoOrder;
    void topo(int i)
    {
        visited[i] = true;
        for(auto x:adj[i])
        {
            if(!visited[x])
                topo(x);
        }
        st.push(i);
    }
    bool checkCycle(int n)
    {
        unordered_map<int,int> pos;
        int index = 0;
        while(!st.empty())
        {
            pos[st.top()] = index++;
            topoOrder.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
                //if position of child less than parent means cycle detected
                if(pos[i]>pos[x])
                    return true;
            }
        }
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        for(auto x:p)
            adj[x[1]].push_back(x[0]);
        visited.resize(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                topo(i);
        }
        // if cycle exist
        if(checkCycle(n))
            return {};
        return topoOrder;
    }
};