class Solution {
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i)
    {
	    visited[i]=true;
	    for(int j=0;j<M.size();j++)
		    if(M[i][j]==1 && !visited[j])
			    dfs(M,visited,j);
    }
public:
    int findCircleNum(vector<vector<int>>& c) {
        int n = c.size();
        if(n==0)
            return 0;
        int ans=0;
        // to keep track of visited node
        vector<bool> visited(n);
        for(int i=0;i<n;i++)
        {
            // if a node is not visited we will visite all those nodes connected
            // directly or indirectly from currrent node,as they are in group
            if(!visited[i])
            {
                ans++;
                dfs(c,visited,i);
            }    
        }
        return ans;
    }
};