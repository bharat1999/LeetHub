class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        // first = weight second = node index in array
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        
        vector<bool> inMST(n);
        
        // entering first coordinate
        heap.push({0,0});
        int MSTcost = 0;
        int edges = 0;
        
        // MST have exactly nodes - 1 edges
        while(edges < n)
        {
            auto x = heap.top();
            heap.pop();
            int weight = x.first;
            int currNode = x.second;
            
            if(inMST[currNode])
                continue;
            
            inMST[currNode] = true;
            MSTcost += weight;
            edges++;
            
            for(int i=0;i<n;++i)
            {
                // if next node not in MST add to heap
                if(!inMST[i])
                {
                    int nextNodeWeight = abs(points[currNode][0]-points[i][0]) +
                                         abs(points[currNode][1]-points[i][1]);
                    heap.push({nextNodeWeight,i});
                }
            }
        }
        return MSTcost;
    }
};