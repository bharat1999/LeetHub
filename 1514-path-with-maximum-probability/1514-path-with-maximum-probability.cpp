class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        using pi = pair<double,int> ;
        vector<vector<pi>> g(n);     
        for (int i=0; i<edges.size(); i++) 
        {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back({succProb[i],v});
            g[v].push_back({succProb[i],u});
        }
        priority_queue<pi> pq;
        pq.push({1, start});
        vector<double> probs(n, 0);
        probs[start] = 1;
        while (!pq.empty()) 
        {
            auto [prob, curr] = pq.top();
            pq.pop();    
            if (prob < probs[curr]) continue;
            for (auto [pathsucc, to] : g[curr]) 
            {
                if (pathsucc * prob > probs[to]) 
                {
                    probs[to] = pathsucc * prob; 
                    pq.push({pathsucc * prob, to});
                }
            }
        }
        
        return probs[end];
    }
};