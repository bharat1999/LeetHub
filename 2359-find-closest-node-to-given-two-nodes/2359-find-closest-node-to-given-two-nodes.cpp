class Solution {
public:
    int n;
    void bfs(vector<int> edges,int src,vector<int>&d){
        queue<int>q;
        vector<bool> visited(n,false);
        q.push(src);
        d[src]=0;
        visited[src]=true;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            int next = edges[cur];
            if(next!=-1 and !visited[next])
            {
                visited[next] = true;
                d[next]=1+d[cur];
                q.push(next);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n=edges.size();
        vector<int>d1(n,1e9),d2(n,1e9);
        bfs(edges,node1,d1);
        bfs(edges,node2,d2);
        int ans=1e9+10,idx=-1;
        for(int i=0;i<n;i++)
        {
            if(d1[i]!=1e9 and d2[i]!=1e9)
            {
                if(ans>max(d1[i],d2[i]))
                {
                    ans=max(d1[i],d2[i]);
                    idx=i;
                }
            }
        }
        return idx;
    }
};