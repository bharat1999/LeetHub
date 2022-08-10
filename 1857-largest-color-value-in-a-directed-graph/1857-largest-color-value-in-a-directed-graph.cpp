class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        int nodes = 0;
        // It will be used to store the max colors for each color till that node
        int dp[n][26];
        memset(dp,0,sizeof(dp));
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            nodes++;
            //increment color value of current node
            dp[cur][colors[cur]-'a']++;
            // now we will visit neighbours and update the color value of neighbour
            for(auto n:adj[cur])
            {
                inDegree[n]--;
                // updating color value for each color till nth node
                // if cureent path increase color value it will be increased
                for(int color=0;color<26;color++)
                    dp[n][color] = max(dp[n][color],dp[cur][color]);
                if(inDegree[n]==0)
                    q.push(n);
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++)
            for(int j=0;j<26;j++)
                ans = max(ans,dp[i][j]);
        return nodes==n?ans:-1;
    }
};