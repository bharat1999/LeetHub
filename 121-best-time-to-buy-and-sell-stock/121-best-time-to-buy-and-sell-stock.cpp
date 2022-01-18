class Solution {
public:
    int maxProfit(vector<int>& p) {
        int curmin=p[0];
        int res=0;
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            if(p[i]>curmin)
                res=max(res,p[i]-curmin);
            else
                curmin=p[i];
        }
        return res;
    }
};