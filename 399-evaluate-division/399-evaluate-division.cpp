class Solution {
    void dfs(string start,string end,unordered_map<string,double>& mp1,unordered_map<string,vector<string>>& mp2,double& val,unordered_map<string,bool>& visited,bool& found)      {
        visited[start]=true;
        if(found==true)
            return ;
        for(auto child:mp2[start])
        {
            if(!visited[child])
            {
                val*=mp1[start+"->"+child];
                // we got the answer
                if(end==child)
                {
                    found=true;
                    return ;
                }
                dfs(child,end,mp1,mp2,val,visited,found);
                // if answer found return true
                if(found==true)
                    return ;
                // if not found we try other path so divide for backtracking
                else{
                    val/=mp1[start+"->"+child];
                }
            }
        }
       
        
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,double> mp1;
        unordered_map<string,vector<string>> mp2; 
        int n = equations.size();
        vector<double> ans;
        for(int i=0;i<n;i++)
        {
            string u =  equations[i][0];
            string v =  equations[i][1];
            mp1[u+"->"+v] = values[i];
            mp1[v+"->"+u] = 1/values[i];
            mp2[u].push_back(v);
            mp2[v].push_back(u);
        }
        
        for(int i=0;i<queries.size();i++)
        {
            string start=queries[i][0];
            string end=queries[i][1];
            // if start or ending vertex not in graph
            if(mp2.find(start)==mp2.end() or mp2.find(end)==mp2.end())
                ans.push_back(-1);
            else
            {    
                double val=1;
                unordered_map<string,bool> visited;
                bool found=false;
                if(start==end)
                    found=true;
                else
                    dfs(start,end,mp1,mp2,val,visited,found);
                if(found==true)
                    ans.push_back(val);
                else
                    ans.push_back(-1);
                
            }
        }
        return ans;
    }
};