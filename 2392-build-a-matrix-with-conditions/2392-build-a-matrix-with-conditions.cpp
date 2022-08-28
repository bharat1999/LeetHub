class Solution {
private:
    // to get the topo order of graph and count of nodes
    vector<int> getTopo(int k, vector<int> adj[], int &cnt){
        vector<int> indegree(k+1);
        
        for(int i=1; i<=k; i++)
        {
            for(auto n : adj[i]) 
                indegree[n]++;
        }
        
        queue<int> q;
        for(int i=1; i<=k; i++) 
            if(indegree[i] == 0) 
                q.push(i);
        
        vector<int> topo;
        
        
        while(!q.empty())
        {
            int curr_node = q.front(); 
            q.pop(); 
            cnt++;
            topo.push_back(curr_node);
            
            for(auto n : adj[curr_node])
            {
                indegree[n]--;
                if(indegree[n] == 0) 
                    q.push(n);
            }
        }
        
        return topo;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        // adjacency list considering row condtions
        vector<int> adjRow[k+1];
        // we can go from above to below
        for(auto r : rc)
            adjRow[r[0]].push_back(r[1]);
        // adjacency list considering col condtions
        vector<int> adjCol[k+1];
        for(auto c : cc)
            adjCol[c[0]].push_back(c[1]);
        int rowCnt = 0, colCnt = 0;
        
        vector<int> topoRow = getTopo(k, adjRow, rowCnt);
        vector<int> topoCol = getTopo(k, adjCol, colCnt);
        
        // if any topo order of row or col have lesser nodes mean cycle exist
        if(rowCnt != k || colCnt != k)
            return {};
        
        for(auto x:topoRow)
            cout<<x<<" ";
        cout<<endl;
        for(auto x:topoCol)
            cout<<x<<" ";
        cout<<endl;
        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        vector<pair<int,int>> num(k+1);
        
        for(int i=0; i<k; i++){
            num[topoRow[i]].first = i;
            num[topoCol[i]].second = i;
        }
        

        
        for(int i=1; i<=k; i++){
            pair<int,int> p = num[i];
            ans[p.first][p.second] = i;
        }
        
        return ans;
        
    }
};