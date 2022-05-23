class Solution {
    int ans;
    int z,o;
    vector<pair<int,int>> count;
    int dp[600][101][101];
    int solve(int i,int n, vector<string>& str,int zero,int one,int c)
    {
        if(i==n)
        {   
            return 0;
        }
        if(dp[i][zero][one]!=-1)
            return dp[i][zero][one];
        // not take current str
        int res1 = solve(i+1,n,str,zero,one,c);
        // take currents str
        int res2 =0;
        if(zero+count[i].first<= z and one+count[i].second<=o)
            res2 = 1+solve(i+1,n,str,zero+count[i].first,one+count[i].second,c+1);
        return dp[i][zero][one]=max(res1,res2);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        z = m;
        o = n;
        int size = strs.size();
        memset(dp,-1,sizeof(dp));
        for(auto x:strs)
        {
            int t1=0,t2=0;
            for(int i=0;i<x.size();i++)
            {
                if(x[i]=='0')
                    t1++;
                else
                    t2++;
            }
            count.push_back({t1,t2});
        }
        return solve(0,size,strs,0,0,0);
            
        
    }
};